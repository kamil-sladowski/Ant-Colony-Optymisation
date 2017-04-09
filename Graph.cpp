//
// Created by Kamil on 2017-04-09.
//

#include <utility>
#include <iostream>
#include<iomanip>
#include<memory>
#include "Graph.h"
#define N 6
using namespace std;

//extern int N;


Graph::Graph(){
    adjacencyGraph = createMatrix();
    initializeAdjacencyGraph(adjacencyGraph);
    for (int i = 0; i < N; ++i)
        adjacencyGraph[i][i] = 1;
    showAdjacencyGraph();
    fermon = createMatrix();
}
/*
Graph& Graph::operator=(Graph const& ex){
}
*/

void Graph::evaporateFermons(){
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            fermon[i][j] -=1;
}

void Graph::leaveFermon(pair<int, int>point){
    fermon[point.first][point.second] +=1;
}

int **createMatrix() {
    int **matrix = new int *[N]; //Tworzenie dynamicznej tablicy o wymiarach NxN
    for (int i = 0; i < N; ++i)
        matrix[i] = new int[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 0; //-1
        }
    }
    return matrix;
}

void initializeAdjacencyGraph(int ** adjacencyGraph){ //for tests
    adjacencyGraph[0][1] = 14;//A-B
    adjacencyGraph[0][2] = 17;// A-C
    adjacencyGraph[1][2] = 2; //C-B
    adjacencyGraph[0][3] = 8; // B-D
    adjacencyGraph[2][0] = 17; //C-A
    adjacencyGraph[3][2] = 31; //D-C
}

void Graph::showAdjacencyGraph()
{
    cout << setw(SETWVALUE);
    for(int j = 0; j<N; j++)
    {
        for(int i = 0; i<N; i++)
        {
            cout << adjacencyGraph[i][j]<<setw(SETWVALUE);
        }
        cout << endl;
    }
    cout << endl;
}