
#include "Node.h"
#include <iostream>
#include <utility>
#include <string>

Node::Node() {
    number = -1;
    name = '#';
}

Node::Node(int number){
    this->number = number;
    this->name = static_cast<char>('A' + number);
}

