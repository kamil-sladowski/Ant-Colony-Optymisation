//
// Created by Kamil on 2017-04-09.
//
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include "Node.h"
#ifndef ANT2_GRAPH_H
#define ANT2_GRAPH_H
#define SETWVALUE 5

using namespace std;

class Graph{
private:
    float evaporationSpeed;

public:
    int ** adjacencyGraph;
    double ** fermon;

    Graph(float);
    //Graph(Graph &);

    void evaporateFermons();
    void leaveFermon(pair<int, int>);
    void showAdjacencyGraph();
    vector<int> getConnections(int currentPosition, vector<bool> visited);
    float getFermon(int, int);
    int getWayLength(int, int);
};

template<typename T>
T **createMatrix(T initializer);
void initializeAdjacencyGraph(int ** adjacencyGraph);


#endif //ANT2_GRAPH_H
