#pragma once

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int source,int endNode, string path1, string path2) {
    ifstream fin(path1);
    int k, n;
    fin >> k >> n;

    vector<pair<int, int>> adjList[1000];

    int dist[1000];

    ifstream finn(path2);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        finn >> x >> y >> z;
        adjList[x].push_back({y, z});
    }

    //vector to store all the nodes in the shortest path for each node
    vector<vector<int>> nodes;

    for (int i = 0; i < k; i++) {
        vector<int> temp;
        temp.push_back(i);
        nodes.push_back(temp);
        dist[i] = INF;
    }

    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, source });

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (pair<int, int> v : adjList[u]) {
            int alt = dist[u] + v.second;

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

//Dijkstra algorithm to get the shortest distance
int dijkstraForDistance(int source, int endNode, string path1, string path2) {
    ifstream fin(path1);
    int k, n;
    fin >> k >> n;

    vector<pair<int, int>> adjList[1000];

    int dist[1000];

    ifstream finn(path2);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        finn >> x >> y >> z;
        adjList[x].push_back({ y, z });
    }

    for (int i = 0; i < k; i++) {
        dist[i] = INF;
    }

    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, source });

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (pair<int, int> v : adjList[u]) {
            int alt = dist[u] + v.second;

            if (alt < dist[v.first]) {
                dist[v.first] = alt;
                pq.push({ alt, v.first });
            }
        }
    }
    return dist[endNode];
}
