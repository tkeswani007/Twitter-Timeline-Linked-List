#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class DNode {
public:
    string ID, UNAME, TWEET;
    DNode *NEXT, *PREV;
    DNode(string x, string y, string z) : ID(x), UNAME(y), TWEET(z), NEXT(nullptr), PREV(nullptr) {}
};

class DLinkList {
private:
    DNode *START, *END;
    int TCNT;
    int countNode;

public:
    DLinkList() : START(nullptr), END(nullptr), TCNT(1001), countNode(0) {}

    ~DLinkList() {
        DNode* current = START;
        while (current != nullptr) {
            DNode* next = current->NEXT;
            delete current;
            current = next;
        }
    }

    void getData(string &u, string &t) {
        cout << "Enter User Name: ";
        getline(cin >> ws, u);
        cout << "Enter Tweet Content: ";
        getline(cin, t);
    }

    void insertAtBeginning() {
        string u, t;
        getData(u, t);
        string tid = "TWEET" + to_string(TCNT++);
        DNode* TEMP = new DNode(tid, u, t);

        if (START == nullptr) {
            START = END = TEMP;
        } else {
            TEMP->NEXT = START;
            START->PREV = TEMP;
            START = TEMP;
        }
        countNode++;
        cout << "\nTweet added at the beginning!";
        getch(); // Wait for user to read
    }

    void insertAtEnd() {
        string u, t;
        getData(u, t);
        string tid = "TWEET" + to_string(TCNT++);
        DNode* TEMP = new DNode(tid, u, t);

        if (START == nullptr) {
            START = END = TEMP;
        } else {
            END->NEXT = TEMP;
            TEMP->PREV = END;
            END = TEMP;
        }
        countNode++;
        cout << "\nTweet added at the end!";
        getch(); // Wait for user to read
    }

    void insertAtPosition() {
        if (START == nullptr) {
            insertAtBeginning();
            return;
        }

        int pos;
        cout << "\nEnter position after which to insert (1 to " << countNode << "): ";
        cin >> pos;

        if (pos < 1 || pos > countNode) {
            cout << "\nInvalid position!";
            getch(); // Wait for user to read
            return;
        }

        if (pos == countNode) {
            insertAtEnd();
            return;
        }

        string u, t;
        getData(u, t);
        string tid = "TWEET" + to_string(TCNT++);
        DNode* TEMP = new DNode(tid, u, t);

        DNode* curr = START;
        for (int i = 1; i < pos; i++) {
            curr = curr->NEXT;
        }

        TEMP->NEXT = curr->NEXT;
        TEMP->PREV = curr;
        curr->NEXT->PREV = TEMP;
        curr->NEXT = TEMP;

        countNode++;
        cout << "\nTweet inserted at position " << pos + 1 << "!";
        getch(); // Wait for user to read
    }

    void deleteAtPosition() {
        if (START == nullptr) {
            cout << "\nList is empty!";
            getch(); // Wait for user to read
            return;
        }

        int pos;
        cout << "\nEnter position to delete (1 to " << countNode << "): ";
        cin >> pos;

        if (pos < 1 || pos > countNode) {
            cout << "\nInvalid position!";
            getch(); // Wait for user to read
            return;
        }

        DNode* TEMP = START;
        for (int i = 1; i < pos; i++) {
            TEMP = TEMP->NEXT;
        }

        if (TEMP == START && TEMP == END) {
            START = END = nullptr;
        } else if (TEMP == START) {
            START = START->NEXT;
            START->PREV = nullptr;
        } else if (TEMP == END) {
            END = END->PREV;
            END->NEXT = nullptr;
        } else {
            TEMP->PREV->NEXT = TEMP->NEXT;
            TEMP->NEXT->PREV = TEMP->PREV;
        }

        delete TEMP;
        countNode--;
        cout << "\nNode deleted successfully!";
        getch(); // Wait for user to read
    }

    void showNodes() {
        system("cls");
        if (START == nullptr) {
            cout << "No tweets found.\n";
            getch();
            return;
        }

        cout << "--- Doubly Linked List Traversal ---\n";
        cout << "1. Forward (Head to Tail)\n";
        cout << "2. Backward (Tail to Head)\n";
        char c = getch();

        DNode* TEMP = (c == '1') ? START : END;
        cout << "\nDisplaying Results:\n";

        while (TEMP != nullptr) {
            cout << "[" << TEMP->ID << "] @" << TEMP->UNAME << ": " << TEMP->TWEET << endl;
            TEMP = (c == '1') ? TEMP->NEXT : TEMP->PREV;
        }
        cout << "\nPress any key to return...";
        getch(); // Wait for user to read list
    }

    void MainMenu() {
        while (true) {
            system("cls");
            cout << "===== DOUBLY LINKED LIST MODULE =====\n";
            cout << "1. Insert at Beginning\n";
            cout << "2. Insert at End\n";
            cout << "3. Insert at Specific Position\n";
            cout << "4. Delete Tweet\n";
            cout << "5. Display Tweets\n";
            cout << "6. Back to Main Menu\n";
            cout << "Choice: \n";

            char c = getch();
            if (c == '1') insertAtBeginning();
            else if (c == '2') insertAtEnd();
            else if (c == '3') insertAtPosition();
            else if (c == '4') deleteAtPosition();
            else if (c == '5') showNodes();
            else if (c == '6') return;
        }
    }
};

#endif
