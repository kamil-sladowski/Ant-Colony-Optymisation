//
// Created by Kamil on 2017-04-09.
//

#include "Node.h"
#include <iostream>
#include <utility>
#include <string>
#include<memory>
#define N 6
using namespace std;

//extern int N;

Node::Node() {
    number = -1;
    name = "no name";
}

Node::Node(int number){
    this->number = number;
}


/*
Node::Node(Node & ex){
    name = ex.name;
}

Node& Node::operator=(Node const& ex){
    if(this == &ex)
        return *this;

    name = move(ex.name);
    return *this;
}
*/


