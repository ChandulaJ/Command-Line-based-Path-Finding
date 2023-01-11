#pragma once

#include <iostream>
#include "Color.h" //header file to change the color in the terminal

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

//function to display the shortest path
//need the input from shortest path algorithm
void display_shorestpath() {
    //sample test output taken from the shortest path algorithm
    int shortestPathNodes[10] = { 0, 1, 2, 58, 59, 14, 3, 11, 74, 8 };

    //user input of the starting node address
    cout << "Enter the starting node : " << endl;

    cout << endl;

    //user input of the destination node address
    cout << "Enter the destination node : " << endl;

    cout << endl;

    cout << "===============================================================" << endl;

    //displaying the shortest path node travese order
    cout << "Shortest path : ";
    for (int i = 0; i < 10; i++) {
        cout << shortestPathNodes[i] << " > ";
    }
    cout << endl;

    cout << "===============================================================" << endl;

    cout << endl;
}

//function for displaying map to the user to get the input for start and the destination
void display_Map(int map[43][30]) {
    //array to store the nodes in the graph
    Node* nodes[92];

    int step = 0;

    //traversing in x direction
    for (int j = 1; j < 30; j++) {
        for (int i = 1; i < 43; i++) {
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
                    nodes[step] = new Node(step, i, j);
                    step++;
                }
            }
        }
    }

    //traversing in y direction
    for (int i = 1; i < 43; i++) {
        for (int j = 1; j < 30; j++) {
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
                    nodes[step] = new Node(step, i, j);
                    step++;
                }
            }
        }
    }

    //character array for displaying the map
    char arr[43][30];

    for (int i = 0; i < 43; i++) {
        for (int j = 0; j < 30; j++) {
            if (map[i][j] == 1) {
                arr[i][j] = '.';
            }
            else {
                arr[i][j] = ' ';
            }
        }
    }

    //inserting + signs for the nodes
    for (int i = 0; i < 92; i++) {
        arr[nodes[i]->r][nodes[i]->c] = '+';
    }


    //printing the map to display the node addresses to the user
    char indexv1 = 65;
    for (int i = 0; i < 43; i++) {
        char indexh = 65;
        for (int j = 0; j < 30; j++) {
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

    cout << endl;
}

//function to print the shortest path
//need an input from the shortest path algorithm as an array
void print_Map(int map[43][30]) {
    //array to store the nodes in the graph
    Node* nodes[92];

    int step = 0;

    //traversing in x direction
    for (int j = 1; j < 30; j++) {
        for (int i = 1; i < 43; i++) {
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
                    nodes[step] = new Node(step, i, j);
                    step++;
                }
            }
        }
    }

    //traversing in y direction
    for (int i = 1; i < 43; i++) {
        for (int j = 1; j < 30; j++) {
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
                    nodes[step] = new Node(step, i, j);
                    step++;
                }
            }
        }
    }

    //character array for displaying the map
    char arr[43][30];

    for (int i = 0; i < 43; i++) {
        for (int j = 0; j < 30; j++) {
            if (map[i][j] == 1) {
                arr[i][j] = '.';
            }
            else {
                arr[i][j] = ' ';
            }
        }
    }

    //inserting + signs for the nodes
    for (int i = 0; i < 92; i++) {
        arr[nodes[i]->r][nodes[i]->c] = '+';
    }

    //sample test output taken from the shortest path algorithm
    int shortestPathNodes[10] = { 0, 1, 2, 58, 59, 14, 3, 11, 74, 8 };

    //printing the map
    char indexv2 = 65;
    for (int i = 0; i < 43; i++) {
        char indexh = 65;
        for (int j = 0; j < 30; j++) {
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
                    for (int k = 0; k < 92; k++) {
                        if (nodes[k]->r == i && nodes[k]->c == j) {
                            for (int z = 0; z < 10; z++) {
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