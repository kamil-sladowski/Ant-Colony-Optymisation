#include <iostream>
#include <cstdlib>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "Node.cpp"
#include "Graph.cpp"
#include "Ant.cpp"

#define SETWVALUE 9
#define N 6
#define ANTSPOPULATION 20
using namespace std;

//int N; // wymiar liczba wezlow




int main() {

    srand( time( NULL ) );
    //int nodeNumber = 6; //6 only now
    //::N = nodeNumber;
    cout<< "creation graph " << endl;
    Graph graph1;
    graph1.showAdjacencyGraph();

    cout<< "creation population: " << endl;
    vector<Ant> population (ANTSPOPULATION, {Ant(N, "A")});

     population[1] = {Ant(N, "B")};






    return 0;
}