#include <iostream>
#include <iterator>
#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int *array, int len) { 
    for(int i = 0; i<len; i++) {
        insertPosition(i+1, array[i]);
    }
}

LinkedList::~LinkedList() { }

void LinkedList::insertPosition(int pos, int newNum) {
    // Min position is 1, so if anything below 1 is entered define pos as 1 (head)
    if(pos<=1) {
        pos = 1;
    }
    Node* newNode;

    // If pos is 1 put the new node as the head.
    if(pos==1) {
        newNode->link = head;
        newNode->data = newNum;
        head = newNode;
    }
    // If pos is greater than 1, traverse Node until pos is reached.
    else if(pos > 1) {
        Node* currentNode = head;
        int currentPos = 1;
        while(currentNode != nullptr && currentPos < pos-1) {
            // Traversing nodes, could use traverse function later
            currentNode = currentNode->link;
            currentPos++;
        }
        newNode->link = currentNode->link;
        newNode->data = currentNode->data;
    }
}

bool LinkedList::deletePosition(int pos) { 
    if (pos<1) {
        return false;

    } else {
        Node* currentNode;
        currentNode->link = head;
        while(currentNode->link != nullptr) {
            currentNode = currentNode->link;
        }
        if(currentNode->link == nullptr) {
            return false;
        }
        
    }
}

int get(int pos) { }

int search(int target) { }

void printList() { }




int main() {

    return 0;
}