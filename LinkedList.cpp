#include <iostream>
#include <iterator>
#include <limits>
#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int *array, int len) : head(nullptr) { 
    for(int i = 0; i<len; i++) {
        insertPosition(i+1, array[i]);
    }
}

LinkedList::~LinkedList() { 
    while(head != nullptr) {
        Node* currentNode = head;
        head = head->link;
        delete currentNode;
    }
}

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
    if(head == nullptr) {
        return false;
    }
    if (pos<1) {
        return false;
    } else {
        Node* currentNode = head;
        head = head->link;

        int currentPos = 1;
        while(currentNode->link != nullptr && currentPos < pos-1) {
            currentNode = currentNode->link;
            currentPos++;
        }
        if(currentNode->link != nullptr && currentNode != nullptr) {
            Node* temp = currentNode->link;
            currentNode->link = temp->link;
            delete temp;
            return true;
        }
    }
    return false;
}

int LinkedList::get(int pos) { 
    if(pos<1) {
        std::numeric_limits < int >::max();
    }
    Node* currentNode = head;
    int currentPos = 1;
    while(currentNode != nullptr && currentPos<pos) {
        currentNode = currentNode->link;
        currentPos++;
    }
    if(currentNode != nullptr) {
        return currentNode->data;
    }
}

int LinkedList::search(int target) { 
    Node* currentNode = head;
    int currentPos = 1;
    while(currentNode->link != nullptr) {
        if(currentNode->data == target) {
            return currentPos;
            break;
        }
        currentNode = currentNode->link;
        currentPos++;
    }
    return -1;
}

void LinkedList::printList() { 
    std::cout << "[";
    Node* currentNode = head;
    while(currentNode != nullptr) {
        std::cout << currentNode->data;
        currentNode = currentNode->link;
        if(currentNode != nullptr) {
            std::cout << " ";
        }
    }
    std::cout << "]" << std::endl;
}
