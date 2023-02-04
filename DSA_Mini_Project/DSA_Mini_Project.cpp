// DSA_Mini_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Color.h" //header file to change the color in the terminal
#include "Functions.h"
#include "Doubly_Linked_List.h"

/*
* Instructions :
*
* Insert the height and width repectively in the first line in map.txt which is inside the project folder
* Insert the map to the same map.txt file
* Run the project
* Nodes corresponding to the shortest path will be highlighted in cyan (light blue) color
* Maximum map size is 52 x 52
*
*/

using namespace std;

int main()
{
    //taking the user input for the map
    //int mapArr[43][30];
    string path = "map.txt";

    ifstream fin(path);

    //getting the height and width of the map
    int y, x;
    fin >> y >> x;

    vector<vector<int>> map(y, vector<int>(x));

    //reading the map from a text file
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            int d;
            fin >> d;
            map[i][j] = d;
            //mapArr[i][j] = d;
        }
    }

    //y = 43;
    //x = 30;

    /*
    int** mapArr = new int* [y];
    for (int i = 0; i < y; i++) {
        mapArr[i] = new int[x];
    }
    
    
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            mapArr[i][j] == map[i][j];
        }
    }
    */

    /*
    //enter the map in the map.txt file
    for (int i = 0; i < 43; i++) {
        for (int j = 0; j < 30; j++) {
            int d;
            cin >> d;
            mapArr[i][j] = d;
        }
        cout << endl;
    }
    */

    /*
    //enter the map in the map.txt file
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            int d;
            cin >> d;
            map[i][j] = d;
            mapArr[i][j] = d;
        }
        cout << endl;
    }
    */

    cout << "===============================================================" << endl;
    cout << "Finding the shortest path in a map" << endl;
    cout << "===============================================================" << endl;

    cout << endl;

    /*
    vector<Doubly_Linked_List> list;

    list = generateAdjList(findNodes(path), path);

    for (int i = 0; i < list.size(); i++) {
        list[i].print();
    }
    */

    //displaying map for the user and getting inputs for starting point and destination point
    display_Map(map, findNodes(path), path);

    //displaying the shortest path
    display_shorestpath();

    //displaying the shortest path in the map
    print_Map(map, findNodes(path), path); 
}

