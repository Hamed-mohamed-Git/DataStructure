//
// Created by user on 11/28/25.
//
#ifndef LINKEDLIST_CURSOR_LIST_H
#define LINKEDLIST_CURSOR_LIST_H
#include "../Node/Node.h"

class CursorList{
public:
    // ==============================
    //      Construction & State
    // ==============================
    CursorList();
    ~CursorList();
	bool listIsEmpty() const;
    bool curIsEmpty() const;

    // ==============================
    //          Navigation
    // ==============================
    void toFirst();
    bool atFirst() const;
    void advance();
    void toEnd();
    bool atEnd() const;

    // ==============================
    //       Metrics & Updates
    // ==============================
    int  listSize() const;
    void updateData(int) const;

    // ==============================
    //           Insertion
    // ==============================
    void insertFirst(const int &);
    void insertAfter(const int &);
    void insertBefore(const int &);
    void insertEnd(const int &);
    void orderInsert(const int &);

    // ==============================
    //            Deletion
    // ==============================
    void deleteNode();
    void deleteFirst();
    void deleteEnd();
    void makeListEmpty();

    // ==============================
    //     Search & Traversal
    // ==============================
    static void displayMenu();
    bool search(int);
    void traverse() const;
    void handleSelection(int selection);

private:
    typedef Node * NodePointer;
    NodePointer head, cursor, prev;
};

void handleSelection(int selection, CursorList &list);

#endif //LINKEDLIST_CURSOR_LIST_H