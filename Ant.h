//
// Created by Kamil on 2017-04-09.
//

#ifndef ANT2_ANT_H
#define ANT2_ANT_H


#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "Graph.h"

using namespace std;

//extern int N;

class Ant{
public:
    int time;
    int maxTime;
    vector<bool> visited;
    int traveledDistance;
    Node currentPosition;
    vector<char> visitedNodes;
    shared_ptr<Graph> ptr_to_graph;

    //Ant();
    Ant(int t, int start, shared_ptr<Graph> ptr);
    Ant(const Ant & ex);
    Ant& operator=(Ant const& ex);


    void nextMove();
    Node getPosition();
    void moveToNextNode(int next);
    void looseFermon();
    void getPath();
};

int chooseWay(vector<pair<int, double>> wayPropabilities);
float getRandom();

#endif //ANT2_ANT_H
