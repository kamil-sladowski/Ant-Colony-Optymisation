#ifndef ANT2_ANT_H
#define ANT2_ANT_H


#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "Node.h"
#include "Graph.h"

using namespace std;

class Ant{
    int time;
    int maxTime;
    double LEGTH_PROPORTION;
    vector<bool> visited;
    Node currentPosition;
    vector<pair<int, int>> visitedNodes;
public:
    int traveledDistance;
    shared_ptr<Graph> ptr_to_graph;

    Ant(int t, int start, double lengthProportion, shared_ptr<Graph> ptr);
    Ant(const Ant & ex);
    Ant& operator=(Ant const& ex);


    void nextMove();
    Node getPosition();
    void moveToNextNode(int next);
    void looseFermon();
    int getTraveledDistance();
    vector<pair<int, int> > getVisitedNodes();
    void getPath();
};

int chooseWay(vector<pair<int, double>> wayPropabilities);
float getRandom();

#endif //ANT2_ANT_H
