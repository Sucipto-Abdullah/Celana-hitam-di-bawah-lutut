#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Graph {
private:
    map<string, vector<pair<string, int> > > adjList;

public:
    void tambahEdge(string asal, string tujuan, int jarak);
    void printGraph();
    bool stasiunAda(string nama);
    map<string, int> dijkstra(string start);
};

#endif

