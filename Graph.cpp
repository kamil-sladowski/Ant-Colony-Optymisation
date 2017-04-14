//
// Created by Kamil on 2017-04-09.
//

#include <utility>
#include <iostream>
#include<iomanip>
#include<memory>
#include <vector>
#include "Graph.h"

using namespace std;

extern int N;


Graph::Graph(double speed){
    evaporationSpeed = speed;

    adjacencyGraph = createMatrix(-1);
    getAdjacencyGraphFromFile();
    for (int i = 0; i < N; ++i)
        adjacencyGraph[i][i] = 1;
    fermon = createMatrix<double>(0.1);
    cout << fermon[1][1]<<endl;
}
/*
Graph& Graph::operator=(Graph const& ex){
}
*/

int ** Graph::getAdjacencyGraph(){
    return adjacencyGraph;
}

double ** Graph::getFermons(){
    return fermon;
}


float Graph::getFermon(int x, int y){
    return fermon[y][x];
}

void Graph::evaporateFermons(){
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            fermon[i][j] = (1 - evaporationSpeed)*fermon[i][j]; // -1/L
}

void Graph::leaveFermon(vector<pair<int, int>>points, double wayLength){
    if (wayLength >0) {
        for(auto point : points){
            fermon[point.second][point.first] +=1/wayLength*100;
            fermon[point.first][point.second] +=1/wayLength*100;
        }
    }
}

template<typename T>
T **createMatrix(T initializer) {
    T **matrix = new T *[N];
    for (int i = 0; i < N; ++i)
        matrix[i] = new T[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = initializer;
        }
    }
    return matrix;
}

void initializeAdjacencyGraph(int ** adjacencyGraph){ //for tests
    adjacencyGraph[0][1] = 14;//A-B
    adjacencyGraph[1][0] = 14;//B-A
    adjacencyGraph[0][2] = 17;// A-C
    adjacencyGraph[2][0] = 17; //C-A
    adjacencyGraph[1][2] = 2; //C-B
    adjacencyGraph[2][1] = 20; //B-C
    adjacencyGraph[0][3] = 8; // B-D
    adjacencyGraph[3][0] = 8; // D-B
    adjacencyGraph[3][2] = 31; //D-C
    adjacencyGraph[2][3] = 31; //C-D
}

template <typename T>
void Graph::showMatrix(T ** matrix)
{
    cout << setw(SETWVALUE);
    for(int j = 0; j<N; j++) {
        for(int i = 0; i<N; i++) {
            cout << fixed<< setprecision(4)<< matrix[i][j]<<setw(SETWVALUE);
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> Graph::getConnections(int x, vector<bool> visited){
    vector<int> connections;

    for(int i =0; i<N; i++)
        if(adjacencyGraph[x][i] > 1 && !visited[i])
            connections.push_back(i);

    return connections;
}


int Graph::getWayLength(int x, int y){
    return adjacencyGraph[y][x];
}


void Graph::getAdjacencyGraphFromFile(){
    int a = 0;
    for(int j = 0; j<N; j++) {
        for(int i = 0; i<N; i++) {
            cin>>a;
            adjacencyGraph[j][i] = a;
        }
    }
}