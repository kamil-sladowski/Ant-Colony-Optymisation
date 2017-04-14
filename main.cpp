#include <iostream>
#include <cstdlib>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "Node.cpp"
#include "Graph.cpp"
#include "Ant.cpp"


using namespace std;

int N; // wymiar liczba wezlow
int main() {
    int const ANTSPOPULATION = 200;
    int nodeNumber = 7;
    cin >> nodeNumber;
    ::N = nodeNumber;
    srand( time( NULL ) );
    double evaporationSpeed = 0.4;
    double lengthProportion = 0.05;
    shared_ptr<Graph> ptr_to_graph = make_shared<Graph>(evaporationSpeed);
    ptr_to_graph->showMatrix(ptr_to_graph->getAdjacencyGraph());
    vector<Ant> population;

    for(int i = 0; i<ANTSPOPULATION; i++) {
        population.push_back(Ant(N, rand()%N,lengthProportion, ptr_to_graph));
    }
    for(int i = 0; i<ANTSPOPULATION; i++) {
        for (int j = 0; j < N -1; j++) {
            population[i].nextMove();
            ptr_to_graph->evaporateFermons();
        }
        if (population[i].getVisitedNodes().size() >=N-1) {
            population[i].ptr_to_graph->leaveFermon(population[i].getVisitedNodes(), population[i].getTraveledDistance());
            population[i].getPath();
            cout<< " traveled:  "<< population[i].getTraveledDistance()<<endl;
        }
    }

    ptr_to_graph->showMatrix(ptr_to_graph->fermon);


    return 0;
}

