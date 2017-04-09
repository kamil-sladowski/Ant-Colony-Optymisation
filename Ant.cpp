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
#include "Ant.h"
#define N 6

using namespace std;

Ant::Ant(int max, int start, shared_ptr<Graph> ptr){
    maxTime = max;
    time = 0;
    currentPosition = Node(start);
    //visited = make_unique<bool []>(N);

    for(int i =0; i<N;i++) {
        visited[i] = false;
    }
    visited[0] = true;

    ptr_to_graph=ptr;

}

Ant::Ant(const Ant & ex): maxTime (ex.maxTime), time(ex.time)  {
    currentPosition =ex.currentPosition;
    for (int i =0; i< N; i++)
        visited[i] = ex.visited[i];

    ptr_to_graph = ex.ptr_to_graph;
}

Ant& Ant::operator=(const Ant& ex){
    if(this == &ex) return *this;

    copy(ex.visited, ex.visited + sizeof(ex.visited)/sizeof(*ex.visited), visited);
    //for (int i =0; i< N; i++)
    //    visited[i] = ex.visited[i];

    maxTime = move(ex.maxTime);
    time = move(ex.time);
    currentPosition = move(ex.currentPosition);
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
    vector<int> allConnections = ptr_to_graph->getConnections(currentPosition);
    //ostream_iterator<int> out(cout, " ");
    //copy(allConnections.begin(), allConnections.end(), out);


//...
/*
    double sum =0;
    int position = currentPosition.number;
    int ways = allConnections.size();
    vector<pair<int, double>> wayPropabilities;
    int i=0;
    double temp[ways];
    for(int x: allConnections){
        cout<< " = "<<x<<endl;
        temp[i] = ptr_to_graph->getFermon(make_pair<int, int>(x, position)) *(1/ptr_to_graph->getWayLength(make_pair<int, int>(x, position))); //+power
        sum += temp[i];
        i++;
    }
    i=0;
    for(int x: allConnections){
        wayPropabilities[i] = make_pair<int, double>(x, temp[i]/sum);
    }

*/
    //    wayPropabilities[i] = getWayPropability(i, allConnections, currentPosition.number);


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

/*
pair<int, double> Ant::getWayPropability(int i, vector<int> connections, int position){
int ways = connections.size();
for(int x : connections)
    cout<< " = "<<x<<endl;

    return make_pair<int, double>(0, 0);
}*/