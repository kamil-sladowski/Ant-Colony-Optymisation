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
#include "Ant.h"
#define N 6

using namespace std;

Ant::Ant(int max, std::string start){
    maxTime = max;
    time = 0;
    currentPosition = Node(start); //new
    //visited = make_unique<bool []>(N);


    for(int i =0; i<N;i++) {
        visited[i] = false;
    }

    visited[0] = true;
}

Ant::Ant(const Ant & ex): maxTime (ex.maxTime), time(ex.time)  {
    currentPosition =ex.currentPosition;
    for (int i =0; i< N; i++)
        visited[i] = ex.visited[i];
}

Ant& Ant::operator=(const Ant& ex){
    if(this == &ex) return *this;

    copy(ex.visited, ex.visited + sizeof(ex.visited)/sizeof(*ex.visited), visited);
    //for (int i =0; i< N; i++)
    //    visited[i] = ex.visited[i];

    maxTime = move(ex.maxTime);
    time = move(ex.time);
    currentPosition = move(ex.currentPosition);
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
    return ;
}
Node Ant::getPosition(){
    return currentPosition;
}

int Ant::getNextDirection(vector<int> allConnections){
    int direction = 0;
    //losowanie
    return direction;
}

//int propability()