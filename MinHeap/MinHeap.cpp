// MinHeap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"MinHeapDS.h"
#include "myvector.h"
using namespace std;
int main()
{
    
	MinHeap mh(100);
	
	int ran;
	for (int i = 0; i < 100; i++) {
		ran = rand() % 100000 + rand() % 1000;
		mh.insertKey(ran);
	}

	mh.print();
	cout << mh.getMin() << endl;

    
    /*
	//vector

    myVector<int> myVec;

    // Adding elements to the myVector
    myVec.push_back(10);
    myVec.push_back(20);
    myVec.push_back(30);

    // Accessing elements of the myVector
    for (int i = 0; i < myVec.size(); i++) {
        std::cout << myVec[i] << " ";
    }
    std::cout << std::endl;

    // Modifying elements of the myVector
    myVec[1] = 25;

    // Printing the modified myVector
    for (int i = 0; i < myVec.size(); i++) {
        std::cout << myVec[i] << " ";
    }
    std::cout << std::endl;
    */
}

//this uses vector