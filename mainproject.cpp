#include <iostream>
#include <conio.h>
#include <process.h>
#include "singlelinklist.h"
#include "DOUBLELINKLIST.H"

using namespace std;

class MainController {
public:
    LinkList sList;
    DLinkList dList;

    // calling the classes of both link lists
    void run() {
        while (true) {
            system("cls");
            cout << "==========================================\n";
            cout << "      TWITTER SIMULATOR DATA SYSTEM      \n";
            cout << "==========================================\n\n";
            cout << "1. Manage Singly Linked List (Basic Tweets)\n";
            cout << "2. Manage Doubly Linked List (Advanced Navigation)\n";
            cout << "3. Exit Application\n\n";
            cout << "Choose a module to enter: ";

            char choice = getch();

            if (choice == '1') {
                // go to the Singly Link List menu
                sList.MainMenu();
            }
            else if (choice == '2') {
                // go to the Doubly Link List menu
                dList.MainMenu();
            }
            else if (choice == '3') {
                system("cls");
                cout << "\n\nThanks for using the App!\n";
                cout << "Designed by Tarun Keswani\n\n";
                exit(0); // close the program
            }
            else {
                cout << "\nInvalid choice! Press any key to try again...";
                getch();
            }
        }
    }
};

int main() {
    MainController app;
    app.run();
    return 0;
}
