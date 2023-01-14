// DSA_Mini_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Color.h" //header file to change the color in the terminal
#include "Functions.h"

/*
* Instructions :
*
* Run the project
* Copy and paste all the content in the map.txt file and hit enter to input the map
* Nodes corresponding to the shortest path will be highlighted in cyan (light blue) color
* Maximum map size is 52 x 52
*
*/

using namespace std;

int main()
{
    //taking the user input for the map
    int map[43][30];

    //enter the map in the map.txt file
    for (int i = 0; i < 43; i++) {
        for (int j = 0; j < 30; j++) {
            int d;
            cin >> d;
            map[i][j] = d;
        }
        cout << endl;
    }

    cout << "===============================================================" << endl;
    cout << "Finding the shortest path in a map" << endl;
    cout << "===============================================================" << endl;

    cout << endl;

    //displaying map for the user and getting inputs for starting point and destination point
    display_Map(map);

    //displaying the shortest path
    display_shorestpath();

    //displaying the shortest path in the map
    print_Map(map);
}

