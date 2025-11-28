//
// Created by user on 11/27/25.
//
#include "List.h"
#include <iostream>
#include "../utils/InputHelper.h"
using namespace std;

// ==============================
//    Construction & State
// ==============================
List::List() {
    head = nullptr;
    tail = nullptr;
    index = 0;
}

List::~List() {
    makeListEmpty();
    head = nullptr;
    tail = nullptr;
}

bool List::search(const int data) const {
    if (isEmpty()) return false;

    const Node *current = head;
    while (current != nullptr) {
        if (current->data == data) return true;
        current = current->next;
    }

    return false;
}

bool List::isEmpty() const {
    return head == nullptr;
}

int List::size() const {
    return index + 1;
}

// ==============================
//          Navigation
// ==============================
void List::advance() const {
    if (head == nullptr) {
        return;
    }

    const Node *current = head;
    while (current != nullptr) {
        current = current->next;
    }
}

// ==============================
//          Insertion
// ==============================
void List::insert(const int data) {
    // Init new node
    if (head == nullptr) {
        insertFirst(data);
        return;
    }

    Node *newNode = createNewNode(data);
    tail->next = newNode;
    tail = tail->next;
    index++;
}

void List::insertFirst(const int data) {
    // Init new node
    Node *newNode = createNewNode(data);
    index++;

    // Empty checking
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    // Inserting first
    newNode->next = head;
    head = newNode;
}

void List::insertAt(const int data, const int _index) {
    if (_index < 0) {
        return;
    }

    if (_index > index) {
        insert(data);
        return;
    }

    if (_index == 0) {
        insertFirst(data);
        return;
    }

    // Init node variables
    Node *newNode = createNewNode(data);
    Node *current = head;
    int currentIndex = 0;

    // loop to at node
    while (currentIndex < _index - 1) {
        current = current->next;
        currentIndex++;
    }

    // Inserting first
    newNode->next = current->next;
    current->next = newNode;
}


// ==============================
//           Deletion
// ==============================
void List::deleteFirst() {
    if (isEmpty())
        return;

    Node *current = head->next;
    delete head;
    head = current;
    index--;
}

void List::deleteLast() {
    if (isEmpty())
        return;

    Node *current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    const Node *temp = current->next;
    current->next = nullptr;
    delete temp;
    tail = current;
    index--;
}

void List::makeListEmpty() {
    if (isEmpty())
        return;

    while (index != 0) {
        deleteFirst();
    }

    head = nullptr;
    tail = nullptr;
}

void List::deleteAt(const int _index) {
    if (isEmpty()) return;

    if (_index < 0 || _index > index) {
        return;
    }

    if (_index == 0) {
        deleteFirst();
        return;
    }

    // Init node variables
    Node *current = head;
    int currentIndex = 0;

    // loop to at node
    while (currentIndex < _index - 1) {
        current = current->next;
        currentIndex++;
    }

    // removing the node
    const Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
    index--;
}

// ==============================
//    Display & Interaction
// ==============================
void List::traverse() const {
    if (isEmpty())
        return;

    const Node *current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << ", ";
        current = current->next;
    }
}

void List::handleSelection(const int selection) {
    int data;
    int _index;

    switch (selection) {
        case 1:
            data = cinListElement(">> Add element: ");
            insert(data);
            break;

        case 2:
            data = cinListElement(">> Add first element: ");
            insertFirst(data);
            break;

        case 3:
            data = cinListElement(">> Add element: ");
            _index = cinListElement(">> Enter index: ");
            insertAt(data, _index);
            break;

        case 4:
            _index = cinListElement(">> Remove element at index: ");
            deleteAt(_index);
            break;

        case 5:
            cout << ">> Remove first element selected." << endl;
            deleteFirst();
            break;

        case 6:
            cout << ">> Remove last element selected." << endl;
            deleteLast();
            break;

        case 7:
            cout << ">> Remove all elements selected." << endl;
            makeListEmpty();
            break;

        case 8:
            cout << ">> List is: [";
            traverse();
            cout << "]" << endl;
            break;

        case 9:
            cout << ">> Display list size: " << size() << endl;
            break;

        case 10:
            data = cinListElement(">> Search by: ");
            cout << "Is Found: " << search(data) << endl;
            break;

        case 11:
            cout << "Is Empty: " << isEmpty() << endl;
            break;

        default:
            cout << "Invalid selection. Try again." << endl;
    }
}

void List::displayMenu() {
    using std::cout;
    using std::endl;

    cout << "=============================" << endl;
    cout << "         List Program        " << endl;
    cout << "=============================" << endl;

    cout << "Choose an operation:" << endl;
    cout << "1. Add element" << endl;
    cout << "2. Add element at beginning" << endl;
    cout << "3. Add element at Index" << endl;
    cout << "4. Remove element at Index" << endl;
    cout << "5. Remove first element" << endl;
    cout << "6. Remove last element" << endl;
    cout << "7. Remove all elements" << endl;
    cout << "8. Display list" << endl;
    cout << "9. Display size" << endl;
    cout << "10. Search" << endl;
    cout << "11. Is Empty" << endl;
    cout << "0. Exit" << endl << endl;
}
