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


#define ANTSPOPULATION 20
using namespace std;

int N; // wymiar liczba wezlow


int main() {
    int nodeNumber = 7;
    cin >> nodeNumber;
    ::N = nodeNumber;
    srand( time( NULL ) );

    float evaporationSpeed = 0.05;
    shared_ptr<Graph> ptr_to_graph = make_shared<Graph>(evaporationSpeed);
    ptr_to_graph->showAdjacencyGraph();
    //vector<Ant> population (ANTSPOPULATION, Ant(N, rand()%N, ptr_to_graph));
    vector<Ant> population;


    //auto generateRandomPopulation = [&](auto ptr_to_graph){return Ant(N, rand()%N, ptr_to_graph);};
    //generate(population.begin(), population.end(), [&](){ return Ant(N, rand()%N, ptr_to_graph);});
    //generate(population.begin(), population.end(), generateRandomPopulation(ptr_to_graph));



    for(int i = 0; i<ANTSPOPULATION; i++) {
        population.push_back(Ant(N, rand()%N, ptr_to_graph));
    }
    for(int i = 0; i<ANTSPOPULATION; i++) {
        for (int j = 0; j < N -1; j++) {
            population[i].nextMove();
        }
        //cout <<"one ant finished"<<endl;
        ptr_to_graph->evaporateFermons();
        population[i].getPath();
    }


    return 0;
}