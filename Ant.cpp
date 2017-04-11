//
// Created by Kamil on 2017-04-09.
//

#include <iostream>
#include <cstdlib>
#include <utility>
#include <string>
#include <cstring>
#include <vector>
#include<memory>
#include <iterator>
#include <random>
#include "Ant.h"
#define N 4

using namespace std;

Ant::Ant(int max, int start, shared_ptr<Graph> ptr): visited(N,false){
    maxTime = max;
    time = 0;
    currentPosition = Node(start);
    visited[currentPosition.number] = true;
    traveledDistance = 0;
    visitedNodes.push_back(currentPosition.name);
    ptr_to_graph=ptr;

}

Ant::Ant(const Ant & ex): maxTime (ex.maxTime), time(ex.time), visited(N,false), traveledDistance(ex.traveledDistance)  {
    currentPosition = ex.currentPosition;
    //copy(ex.visitedNodes.begin(), ex.visitedNodes.end(), visitedNodes);
    for (int i =0; i< N; i++)
        visited[i] = ex.visited[i];

    visitedNodes.push_back(ex.visitedNodes[0]);
    ptr_to_graph = ex.ptr_to_graph;
}

Ant& Ant::operator=(const Ant& ex){ //nieuzywany
    if(this == &ex) return *this;

    //copy(ex.visited.begin(), ex.visited.end(), visited);
    visited.resize(N,false);
    for (int i =0; i< N; i++)
        visited[i] = ex.visited[i];

    maxTime = move(ex.maxTime);
    time = move(ex.time);
    currentPosition = move(ex.currentPosition);
    traveledDistance = move(ex.traveledDistance);
    ptr_to_graph = ex.ptr_to_graph;
    return *this;

}



/*
Ant::Ant(Ant & ex): maxTime (ex.maxTime), time(ex.time), currentPosition (ex.currentPosition),
                visited(unique_ptr<bool[]>(ex.visited ? new bool(ex.visited) : nullptr)){ //*ex.visited
    cout <<"c-cor cop"<<endl;
    //visited.reset(new bool(*ex.visited));
    //memcpy(visited, ex.visited, sizeof(bool)*N);
}


Ant& Ant::operator=(const Ant& ex){
    if(this == &ex) return *this;
    cout << "operator"<< endl;
    try {
        visited.reset(new bool[N]);
        //visited.reset(new bool(ex.visited));//*ex.visited
    }
    catch(exception &e){
        e.what();
    }
        cout << "next "<< endl;
    maxTime = move(ex.maxTime);
    time = move(ex.time);
    currentPosition = move(ex.currentPosition);
    return *this;
}
*/


void Ant::nextMove(){
    vector<int> allConnections = ptr_to_graph->getConnections(currentPosition.number, visited);

    int ways = allConnections.size();
    if(ways >0){
            double sum = 0;
            int position = currentPosition.number;
            int i =0, nextWay= 0;
            double temp[ways];
            vector<pair<int, double>> wayPropabilities;
            for (int x: allConnections) {
                temp[i] = ptr_to_graph->getFermon(x, position) / (ptr_to_graph->getWayLength(x, position)); //+power
                sum += temp[i];
                i++;
            }
            i = 0;

            for (int x: allConnections) {
                wayPropabilities.push_back(make_pair<int, double>((int) x, (double) temp[i] / sum));
                //cout << " way to: " << wayPropabilities[i].first << " propability: " << wayPropabilities[i].second << endl;
                i++;
            }

            nextWay = chooseWay(wayPropabilities);
            //cout << " wybrana sciezka " << nextWay << endl;
            moveToNextNode(nextWay);
    }
    else
        cout<< "slepa uliczka"<<endl;
    return;

}
Node Ant::getPosition(){
    cout<< "current position " << currentPosition.number<< "  "<< currentPosition.name<<endl;
    return currentPosition;
}


int chooseWay(vector<pair<int, double>> wayPropabilities) {
    float randomResult = getRandom();
    float k = 0;
    int i = 0;

    do {
        k += wayPropabilities[i].second;
        i++;
    } while (k <= randomResult && i < wayPropabilities.size());

     return wayPropabilities[i-1].first;
     }

void Ant::moveToNextNode(int next){
    time++;
    traveledDistance+= ptr_to_graph->getWayLength(next, currentPosition.number);
    ptr_to_graph->leaveFermon(make_pair(next, currentPosition.number));
    currentPosition = Node(next);
    visitedNodes.push_back(currentPosition.name);

    visited[next] = true;
}

void Ant::getPath() {
    //ostream_iterator<char> out(cout, " -> ");
    //copy(visitedNodes.begin(), visitedNodes.end(), out);

    for (char i : visitedNodes)
        cout << i << " ->";

    cout << endl;
}

float getRandom(){
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<float> dist(0.0, 1.0);
    return dist(mt);
}
