#include <iostream>
#include "utils/InputHelper.h"
using namespace std;

int main() {
    while (true) {
        showProgramMenu();
        cout << endl << "Choose list type: ";
        int option;
        cin >> option;

        if (option == 0) {

            cout << "Exiting program..." << endl;
            break;
        }

        switch (option) {
            case 1: {
                runListProgram();
                break;
            }
            case 2: {
                runCursorListProgram();
                break;
            }
            default:
                cout << "Invalid selection. Try again." << endl;
        }
    }

    return 0;
}
