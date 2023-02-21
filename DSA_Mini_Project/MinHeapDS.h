#pragma once

#include <iostream>
#include "myvector.h"//myVector datastructure is used here
using namespace std;

class MinHeap {
public:
    MinHeap(int capacity);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int extractMin();
    void insertKey(int k);
    void decreaseKey(int i, int new_val);
    int getMin();
    void print();

private:
    myVector<int> harr;
    int heap_size;
    void minHeapify(int i);
};

MinHeap::MinHeap(int capacity) {
    heap_size = 0;
    harr.resize(capacity);
}

int MinHeap::extractMin() {
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    minHeapify(0);
    return root;
}

void MinHeap::insertKey(int k) {
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::minHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        minHeapify(smallest);
    }
}

int MinHeap::getMin() { return harr[0]; }

void MinHeap::print() {
    for (int i = 0; i < heap_size; i++) {
        cout << harr[i] << " ";
    }
    cout << endl;
}