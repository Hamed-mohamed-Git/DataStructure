#ifndef LINKEDLIST_UTILS_INPUT_HELPER_H
#define LINKEDLIST_UTILS_INPUT_HELPER_H

#include <iostream>
#include "../List/List.h"
#include "../cursorList/CursorList.h"

using namespace std;

inline int cinListElement(const char *message) {
    cout << message;
    int data;
    cin >> data;
    return data;
}

inline void showProgramMenu() {
    cout << "=============================" << endl;
    cout << "    Data Structures Menu     " << endl;
    cout << "=============================" << endl;
    cout << "1. Work with List" << endl;
    cout << "2. Work with CursorList" << endl;
    cout << "0. Exit Program" << endl;
}

inline void runListProgram() {
    List list;
    int selection;

    List::displayMenu();
    cout << endl << "Enter selection: ";
    cin >> selection;

    while (true) {
        if (selection == 0) {
            cout << "Returning to main menu..." << endl;
            break;
        }

        list.handleSelection(selection);
    }
}

inline void runCursorListProgram() {
    CursorList cursorList;
    int selection;

    CursorList::displayMenu();
    cout << endl << "Enter selection: ";
    cin >> selection;

    while (true) {
        if (selection == 0) {
            cout << "Returning to main menu..." << endl;
            break;
        }

        cursorList.handleSelection(selection);
    }
}

#endif // LINKEDLIST_UTILS_INPUT_HELPER_H

