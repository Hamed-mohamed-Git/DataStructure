//
// Created by user on 11/28/25.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

class Node {
public:
    int data;
    Node *next;
    Node();
};

inline Node::Node() {
    data = 0;
    next = nullptr;
}

static Node * createNewNode(const int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    return newNode;
}

#endif //LINKEDLIST_NODE_H