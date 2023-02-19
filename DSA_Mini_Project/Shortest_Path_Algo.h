#pragma once

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

const int INF = 1e9; // A very large value representing infinity

/*
vector<pair<int, int>> adjList[100]; // An adjacency list representing the graph
int dist[100]; // An array to store the shortest distance from the source node to all other nodes

//vector to store all the nodes in the shortest path for each node
vector<vector<int>> nodes;
*/

vector<int> dijkstra(int source,int endNode, string path1, string path2) {
    ifstream fin(path1);
    int k, n;
    fin >> k >> n;

    //int* adjList = new int(n);
    vector<pair<int, int>> adjList[1000]; // An adjacency list representing the graph

    int dist[1000];
    //int* dist = new int(k); // An array to store the shortest distance from the source node to all other nodes

    ifstream finn(path2);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        finn >> x >> y >> z;
        adjList[x].push_back({y, z});
    }

    //vector to store all the nodes in the shortest path for each node
    vector<vector<int>> nodes;

    // Initialize all distances to infinity
    for (int i = 0; i < k; i++) {
        vector<int> temp;
        temp.push_back(i);
        nodes.push_back(temp);
        dist[i] = INF;
    }
    // Initialize the distance to the source node to 0
    dist[source] = 0;

    // Create a priority queue to store the next node to process
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Add the source node to the priority queue
    pq.push({ 0, source });

    // Continue processing nodes until the priority queue is empty
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // If we've already processed this node, continue
        if (d > dist[u]) continue;

        // For each neighbor of the current node
        for (pair<int, int> v : adjList[u]) {
            // Calculate the distance to the neighbor
            int alt = dist[u] + v.second;

            // If the new distance is shorter than the old one, update it and add the neighbor to the priority queue
            if (alt < dist[v.first]) {
                dist[v.first] = alt;
                for (int i = 0; i < nodes[u].size(); i++) {
                    nodes[v.first].push_back(nodes[u][i]);
                }
                pq.push({ alt, v.first });
            }
        }
    }
    return nodes[endNode];
}
