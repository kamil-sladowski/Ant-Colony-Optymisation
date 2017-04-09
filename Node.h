//
// Created by Kamil on 2017-04-09.
//

#ifndef ANT2_NODE_H
#define ANT2_NODE_H
#define SETWVALUE 9

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    string name;
    Node();
    Node(std::string name);
    Node(Node & ex);

    Node& operator= (Node const& ex);
    vector<int> getConnections();
};


#endif //ANT2_NODE_H
