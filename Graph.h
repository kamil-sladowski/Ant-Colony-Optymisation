//
// Created by Kamil on 2017-04-09.
//
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#ifndef ANT2_GRAPH_H
#define ANT2_GRAPH_H
#define SETWVALUE 9

using namespace std;

class Graph{
public:
    int ** adjacencyGraph;
    int ** fermon;

    Graph();
    //Graph(Graph &);

    void evaporateFermons();
    void leaveFermon(pair<int, int>);
    void showAdjacencyGraph();

};


int **createMatrix();
void initializeAdjacencyGraph(int ** adjacencyGraph);


#endif //ANT2_GRAPH_H
