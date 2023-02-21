#pragma once

#include <iostream>
#include <fstream> //library to get inputs from a file
#include <vector>
#include "Color.h" //header file to change the color in the terminal
#include "Doubly_Linked_List.h"
#include "Shortest_Path_Algo.h"

using namespace std;

//Node class
class Node {
public:
    int num; //node number
    int c; //column number
    int r; //row number

    //default constructor
    Node() {

    }

    //overloaded constructor
    Node(int number, int row, int column)
    {
        num = number;
        r = row;
        c = column;
    }
};

//function for finding the nodes
vector<Node*> findNodes(string path) {
    ifstream fin(path);
    int y, x;
    fin >> y >> x;

    vector<Node*> nodes;
    
    //dynamic size 2d array for map
    int** map = new int* [y];
    for (int i = 0; i < y; i++) {
        map[i] = new int[x];
    }

    //inserting elements to the map array
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            int d;
            fin >> d;
            map[i][j] = d;
        }
    }

    int step = 0;

    //here x-1 and y-1 is used to prevent accessing pointers beyond the allocated memory of map array
    //traversing in x direction
    for (int j = 1; j < x-1; j++) {
        for (int i = 1; i < y-1; i++) {
            int value = map[i][j];

            int up, down, left, right;

            up = map[i - 1][j];
            down = map[i + 1][j];
            right = map[i][j + 1];
            left = map[i][j - 1];

            //checking conditions for junctions
            bool cdn1 = up || right;
            bool cdn2 = up || left;
            bool cdn3 = down || right;
            bool cdn4 = down || left;

            //checking condition for L and T junctions
            bool cdn = cdn1 || cdn2 || cdn3 || cdn4;

            //checking in x direction for the conditions to identify the juctions and create nodes for each junction
            if (value == 1 && ((right == 0 && left != 0) || (left == 0 && right != 0))) {
                if (cdn == 1) {
                    Node* temp = new Node(step, i, j);
                    nodes.push_back(temp);
                    step++;
                }
            }
        }
    }

    //traversing in y direction
    for (int i = 1; i < y-1; i++) {
        for (int j = 1; j < x-1; j++) {
            int value = map[i][j];

            int up, down, left, right;

            up = map[i - 1][j];
            down = map[i + 1][j];
            right = map[i][j + 1];
            left = map[i][j - 1];

            //checking conditions for junctions
            bool cdn1 = up || right;
            bool cdn2 = up || left;
            bool cdn3 = down || right;
            bool cdn4 = down || left;

            //checking condition for L and T junctions
            bool cdnj1 = cdn1 || cdn2 || cdn3 || cdn4;
            //checking condition for + junction
            bool cdnj2 = up && down && left && right;

            //checking in y direction for the conditions to identify the juctions and create nodes for each junction
            if (value == 1 && ((down == 0 && up != 0) || (up == 0 && down != 0)) && !((right == 0 && left != 0) || (left == 0 && right != 0)) || cdnj2) {
                if (cdnj1 == 1 || cdnj2) {
                    Node* temp = new Node(step, i, j);
                    nodes.push_back(temp);
                    step++;
                }
            }
        }
    }
    return nodes;
}

//function to display the shortest path
void display_shorestpath(vector<int> path) {
    cout << "===============================================================" << endl;

    //displaying the shortest path node travese order
    cout << "Shortest path : ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " > ";
    }
    cout << endl;

    cout << "===============================================================" << endl;

    cout << endl;
}

//function to generate the map for output display
vector<vector<char>> generateMap(vector<vector<int>> map, string path) {
    vector<Node*> nodes = findNodes(path);

    ifstream fin(path);
    int y, x;
    fin >> y >> x;

    vector<vector<char>> arr(y, vector<char>(x));

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (map[i][j] == 1) {
                arr[i][j] = '.';
            }
            else {
                arr[i][j] = ' ';
            }
        }
    }

    //inserting + signs for the nodes
    for (int i = 0; i < nodes.size(); i++) {
        arr[nodes[i]->r][nodes[i]->c] = '+';
    }

    return arr;
}

vector<int> getShortestPath(int start, int end) {
    string path1 = "weightedGraphDetails.txt";
    string path2 = "weightedGraph.txt";

    vector<int> path = dijkstra(start, end, path1, path2);

    //sorting algorithm to sort the path vector
    for (int step = 1; step < path.size(); step++) {
        int key = path[step];

        int j = step - 1;

        while (j >= 0 && key < path[j]) {
            path[j + 1] = path[j];
            j--;
        }

        path[j + 1] = key;
    }

    //std::sort(path.begin(), path.end());
    auto last = std::unique(path.begin(), path.end());
    path.erase(last, path.end());

    return path;
}

int getShortestDistance(int start, int end) {
    string path1 = "weightedGraphDetails.txt";
    string path2 = "weightedGraph.txt";

    int distance = dijkstraForDistance(start, end, path1, path2);

    return distance;
}

//function for displaying map to the user to get the input for start and the destination
void display_Map(vector<vector<int>> map, vector<Node*> nodes, string path) {
    ifstream fin(path);
    int y, x;
    fin >> y >> x;

    vector<vector<char>> arr = generateMap(map, path);

    //printing the map to display the node addresses to the user
    char indexv1 = 65;
    for (int i = 0; i < y; i++) {
        char indexh = 65;
        for (int j = 0; j < x; j++) {
            if (i == 0 && j == 0) {
                cout << ' ' << "  ";
            }
            else if (i == 0) {
                cout << indexh << "  ";
                indexh++;
                if (indexh > 90 && indexh < 97) {
                    indexh = 97;
                }
            }
            else if (j == 0) {
                cout << indexv1 << "  ";
                indexv1++;
                if (indexv1 > 90 && indexv1 < 97) {
                    indexv1 = 97;
                }
            }
            else {
                cout << arr[i][j] << "  ";
            }
        }
        cout << endl;
    }

    cout << endl;

    cout << "===============================================================" << endl;

    cout << "Index List of the Vertices" << endl;

    cout << endl;
    
    for (int i = 0; i < nodes.size(); i++) {
        char indexHorizontal = 65;
        char indexVertical = 65;

        indexHorizontal = indexHorizontal + nodes[i]->c - 1;

        if (indexHorizontal > 90 && indexHorizontal < 97) {
            int diffh = indexHorizontal - 90;
            indexHorizontal = 97 + diffh-1;
        }

        indexVertical = indexVertical + nodes[i]->r - 1;

        if (indexVertical > 90 && indexVertical < 97 || indexVertical>96) {
            int diffv = indexVertical - 90;
            indexVertical = 97 + diffv - 1;
        }

        cout << indexVertical << " , " << indexHorizontal << "\t=>\t" << nodes[i]->num << endl;
    }

    cout << endl;

    cout << "===============================================================" << endl;

    cout << endl;
}

//function to print the shortest path
void print_Map(vector<vector<int>> map, vector<Node*> nodes, string path, vector<int> shortestPathNodes) {
    ifstream fin(path);
    int y, x;
    fin >> y >> x;

    vector<vector<char>> arr = generateMap(map, path);

    //printing the map
    char indexv2 = 65;
    for (int i = 0; i < y; i++) {
        char indexh = 65;
        for (int j = 0; j < x; j++) {
            if (i == 0 && j == 0) {
                cout << ' ' << "  ";
            }
            else if (i == 0) {
                cout << indexh << "  ";
                indexh++;
                if (indexh > 90 && indexh < 97) {
                    indexh = 97;
                }
            }
            else if (j == 0) {
                cout << indexv2 << "  ";
                indexv2++;
                if (indexv2 > 90 && indexv2 < 97) {
                    indexv2 = 97;
                }
            }
            else {
                //changing color of the nodes related to the shortest path
                if (arr[i][j] == '+') {
                    bool check;
                    for (int k = 0; k < nodes.size(); k++) {
                        if (nodes[k]->r == i && nodes[k]->c == j) {
                            for (int z = 0; z < shortestPathNodes.size(); z++) {
                                if (nodes[k]->num == shortestPathNodes[z]) {
                                    check = true;
                                    break;
                                }
                                else {
                                    check = false;
                                }
                            }
                        }
                    }
                    if (check == true) {
                        cout << dye::on_light_aqua(arr[i][j]) << "  ";
                    }
                    else {
                        cout << (arr[i][j]) << "  ";
                    }
                }
                else {
                    cout << (arr[i][j]) << "  ";
                }
            }
        }
        cout << endl;
    }
}

//automatic adjasancy list generation

void weightedGraphData(vector<Node*> nodes, int count) {
    int numberofNodes = nodes.size();
    int numberofEdges = count;

    string path2 = "weightedGraphDetails.txt";
    ofstream fout(path2);
    fout << numberofNodes <<" " << numberofEdges << endl;
}

int horizontalFrontNodeConnection(vector<Node*> nodes, Node* node) {
    vector<int> distances;

    for (int j = 0; j < nodes.size(); j++) {
        if ((node->r == nodes[j]->r) && (node->c < nodes[j]->c)) {
            distances.push_back(nodes[j]->c - node->c);
        }
        else {
            distances.push_back(INT32_MAX);
        }
    }

    int min = *min_element(distances.begin(), distances.end());

    return min;
}

int horizontalBackNodeConnection(vector<Node*> nodes, Node* node) {
    vector<int> distances;

    for (int j = 0; j < nodes.size(); j++) {
        if ((node->r == nodes[j]->r) && (node->c > nodes[j]->c)) {
            distances.push_back(node->c - nodes[j]->c);
        }
        else {
            distances.push_back(INT32_MAX);
        }
    }

    int min = *min_element(distances.begin(), distances.end());

    return min;
}

int verticalDownNodeConnection(vector<Node*> nodes, Node* node) {
    vector<int> distances;

    for (int j = 0; j < nodes.size(); j++) {
        if ((node->c == nodes[j]->c) && (node->r < nodes[j]->r)) {
            distances.push_back(nodes[j]->r - node->r);
        }
        else {
            distances.push_back(INT32_MAX);
        }
    }

    int min = *min_element(distances.begin(), distances.end());

    return min;
}

int verticalUpNodeConnection(vector<Node*> nodes, Node* node) {
    vector<int> distances;

    for (int j = 0; j < nodes.size(); j++) {
        if ((node->c == nodes[j]->c) && (node->r > nodes[j]->r)) {
            distances.push_back(node->r - nodes[j]->r);
        }
        else {
            distances.push_back(INT32_MAX);
        }
    }

    int min = *min_element(distances.begin(), distances.end());

    return min;
}

vector<Doubly_Linked_List> generateAdjList(vector<Node*> nodes, string path) {
    ifstream fin(path);
    int y, x;
    fin >> y >> x;

    int** map = new int* [y];
    for (int i = 0; i < y; i++) {
        map[i] = new int[x];
    }

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            int d;
            fin >> d;
            map[i][j] = d;
        }
    }

    string path1 = "weightedGraph.txt";
    ofstream fout(path1);
    vector<Doubly_Linked_List> AdjList;

    int count = 0;

    for (int i = 0; i < nodes.size(); i++) {
        Doubly_Linked_List list;
        list.insertFirst(nodes[i]->num);
        AdjList.push_back(list);
    }
    
    for (int i = 0; i < nodes.size(); i++) {
        Node* temp = nodes[i];

        int distFront = horizontalFrontNodeConnection(nodes, temp);
        int distBack = horizontalBackNodeConnection(nodes, temp);
        int distUp = verticalUpNodeConnection(nodes, temp);
        int distDown = verticalDownNodeConnection(nodes, temp);

        if (distFront == INT32_MAX) {
            distFront = 0;
        }
        if (distBack == INT32_MAX) {
            distBack = 0;
        }
        if (distUp == INT32_MAX) {
            distUp = 0;
        }
        if (distDown == INT32_MAX) {
            distDown = 0;
        }

        int connectedNodeNumber;
        
        //front
        bool conditionFront = false;

        for (int j = 0; j < distFront; j++) {
            if (map[temp->r][temp->c + j] == 1) {
                conditionFront = true;
            }
            else {
                conditionFront = false;
                break;
            }
        }
        if (conditionFront) {
            for (int j = 0; j < nodes.size(); j++) {
                if (nodes[j]->c == nodes[i]->c + distFront && nodes[j]->r == nodes[i]->r) {
                    connectedNodeNumber = nodes[j]->num;
                    AdjList[nodes[i]->num].insertLast(connectedNodeNumber);

                    fout << nodes[i]->num <<" " <<connectedNodeNumber << " " <<distFront << endl;

                    count++;
                }
            }
        }
        
        //back
        bool conditionBack = false;

        for (int j = 0; j < distBack; j++) {
            if (map[temp->r][temp->c - j] == 1) {
                conditionBack = true;
            }
            else {
                conditionBack = false;
                break;
            }
        }
        if (conditionBack) {
            for (int j = 0; j < nodes.size(); j++) {
                if (nodes[j]->c == nodes[i]->c - distBack && nodes[j]->r == nodes[i]->r) {
                    connectedNodeNumber = nodes[j]->num;
                    AdjList[nodes[i]->num].insertLast(connectedNodeNumber);

                    //ofstream fout(path1);
                    fout << nodes[i]->num << " " << connectedNodeNumber <<" " << distBack << endl;

                    count++;
                }
            }
        }
        
        //up
        bool conditionUp = false;

        for (int j = 0; j < distUp; j++) {
            if (map[temp->r - j][temp->c] == 1) {
                conditionUp = true;
            }
            else {
                conditionUp = false;
                break;
            }
        }
        if (conditionUp) {
            for (int j = 0; j < nodes.size(); j++) {
                if (nodes[j]->r == nodes[i]->r - distUp && nodes[j]->c == nodes[i]->c) {
                    connectedNodeNumber = nodes[j]->num;
                    AdjList[nodes[i]->num].insertLast(connectedNodeNumber);

                    //ofstream fout(path1);
                    fout << nodes[i]->num << " " << connectedNodeNumber << " " << distUp << endl;

                    count++;
                }
            }
        }
        
        //down
        bool conditionDown = false;

        for (int j = 0; j < distDown; j++) {
            if (map[temp->r + j][temp->c] == 1) {
                conditionDown = true;
            }
            else {
                conditionDown = false;
                break;
            }
        }
        if (conditionDown) {
            for (int j = 0; j < nodes.size(); j++) {
                if (nodes[j]->r == nodes[i]->r + distDown && nodes[j]->c == nodes[i]->c) {
                    connectedNodeNumber = nodes[j]->num;
                    AdjList[nodes[i]->num].insertLast(connectedNodeNumber);

                    //ofstream fout(path1);
                    fout << nodes[i]->num << " " << connectedNodeNumber << " " << distDown << endl;

                    count++;
                }
            }
        }
    }

    weightedGraphData(nodes, count);

    return AdjList;
}

void printInfo(int distance) {
    cout << "===============================================================" << endl;

    cout << endl;

    cout << "Travelling Speeds" << endl;
    cout << endl;
    cout << "Default Speed \t=>\t 50 km/h" << endl;
    cout << "Motor Cycle \t=>\t 40 km/h" << endl;
    cout << "Motor Cycle \t=>\t 60 km/h" << endl;

    double time;
    int speed;
    int unitLength;

    cout << endl;

    cout << "Enter the unit length of the inserted map in meters: ";
    cin >> unitLength;

    cout << endl;

    cout << "Enter the travelling speed : ";
    cin >> speed;

    if (speed != 40 && speed != 60) {
        speed = 50;
    }

    double dist = distance* unitLength;

    double distinKilometers = dist / 1000;

    time = (distinKilometers / speed)*60;

    cout << endl;

    cout << "Travel Distance (in meters)\t\t: " << distance*unitLength << " m" << endl;

    cout << endl;

    cout << "Approximate Travel Time (in minutes) \t: " << time << " minutes" << endl;

    cout << endl;

    cout << "Approximate Travel Time (in seconds) \t: " << time*60 << " seconds" << endl;

    cout << endl;

    cout << "===============================================================" << endl;
}
