#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"

class LinkedList {
    private:
        // Defining the FIRST node (only node with no predecessor)
        Node* head;
    public:
        // General constructor - empty list
        LinkedList();
        
        // Constructor for list of length len
        LinkedList(int *array, int len);
        
        // Destructor that deletes all nodes
        ~LinkedList();

        // Insert newNum to the position pos, where 1 is the front of the list
        void insertPosition(int pos, int newNum);
        
        // Delete node at pos, return true if successful, if out of bounds return false.
        bool deletePosition(int pos);
        
        // Return the data variable at pos. If pos is out of bounds return given statement.
        int get(int pos);

        // Return pos of target, otherwise return -1;
        int search(int target);

        // Print whole list, separated by spaces and encapsulate in [ ];
        // E.g [1 2 3 4 5] or in the case of nothing print nothing.
        void printList();  
};

#endif

