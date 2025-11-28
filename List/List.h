//
// Created by user on 11/27/25.
//
#ifndef LINKEDLIST_LIST_H
#define LINKEDLIST_LIST_H
#include "../Node/Node.h"

class List {
public:
    // ==============================
    //    Construction & State
    // ==============================
    List();
    ~List();
    bool search(int data) const;
    bool isEmpty() const;
    int size() const;

    // ==============================
    //          Insertion
    // ==============================
    void insert(int data);
    void insertFirst(int data);
    void insertAt(int data, int _index);

    // ==============================
    //           Deletion
    // ==============================
    void deleteFirst();
    void deleteAt(int _index);
    void deleteLast();
    void makeListEmpty();

    // ==============================
    //    Display & Interaction
    // ==============================
    static void displayMenu();
    void traverse() const;
    void handleSelection(int selection);

private:
    Node *head;
    Node *tail;
    int index;
    void advance() const;
};

#endif //LINKEDLIST_LIST_H
