//
// Created by Kamil on 2017-04-09.
//

#ifndef ANT2_ANT_H
#define ANT2_ANT_H

#define SETWVALUE 5

#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "Graph.h"
#define N 6
using namespace std;

//extern int N;

class Ant{
public:
    int time;
    int maxTime;
    bool visited[N];
    //unique_ptr<bool[]> visited;
    //bool *visited ;//= nullptr;
    Node currentPosition;
    shared_ptr<Graph> ptr_to_graph;

    //Ant();
    Ant(int t, int start, shared_ptr<Graph> ptr);
    Ant(const Ant & ex);
    Ant& operator=(Ant const& ex);


    void nextMove();
    Node getPosition();
    int getNextDirection( vector<int> allConnections);
};

//pair<int, double> getWayPropability(int i, vector<int> connections, int position);
void chooseWay();
void move();
void looseFermon();




#endif //ANT2_ANT_H
