#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <math.h>

class Node {
    private:
        // Data is the data held inside the node, link is a pointer to the next Node.
        int data;
        Node* link;
    public:
        Node(int n) : data(n), link(nullptr) {}

    friend class LinkedList;
};


#endif