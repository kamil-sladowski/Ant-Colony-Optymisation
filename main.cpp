#include <iostream>
#include <cstdlib>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "Node.cpp"
#include "Graph.cpp"
#include "Ant.cpp"

#define SETWVALUE 5
#define N 6
#define ANTSPOPULATION 20
using namespace std;

//int N; // wymiar liczba wezlow


int main() {
    //int nodeNumber = 6; //6 only now
    //::N = nodeNumber;
    float evaporationSpeed = 0.05;
    shared_ptr<Graph> ptr_to_graph = make_shared<Graph>(evaporationSpeed);
    ptr_to_graph->showAdjacencyGraph();
    //vector<Ant> population (ANTSPOPULATION, {Ant(N, 0, ptr_to_graph)});
    vector<Ant> population;
    for(int i = 0; i<ANTSPOPULATION; i++) {
        population.push_back({Ant(N, 1, ptr_to_graph)});
    }
    for(int i = 0; i<ANTSPOPULATION; i++) {
        for (int j = 0; j < N - 3; j++) {
            population[i].nextMove();
            ptr_to_graph->evaporateFermons();
        }
        population[0].getPath();
    }


    return 0;
}