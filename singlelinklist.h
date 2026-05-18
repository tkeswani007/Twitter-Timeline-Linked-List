#ifndef LINKLISTSINGLY_H
#define LINKLISTSINGLY_H

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class SNode {
public:
    string ID, UNAME, TWEET;
    SNode *NEXT;
    SNode(string x, string y, string z) : ID(x), UNAME(y), TWEET(z), NEXT(nullptr) {}
};

class LinkList {
private:
    SNode *START, *END;
    int TCNT, countNode;

public:
    LinkList() : START(nullptr), END(nullptr), TCNT(1001), countNode(0) {}

    ~LinkList() {
        SNode* current = START;
        while (current != nullptr) {
            SNode* next = current->NEXT;
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
        SNode* TEMP = new SNode("TWEET" + to_string(TCNT++), u, t);
        if (!START) START = END = TEMP;
        else { TEMP->NEXT = START; START = TEMP; }
        countNode++;
        cout << "\nAdded at beginning! Press enter to go back."; getch();
    }

    void insertAtEnd() {
        string u, t;
        getData(u, t);
        SNode* TEMP = new SNode("TWEET" + to_string(TCNT++), u, t);
        if (!START) START = END = TEMP;
        else { END->NEXT = TEMP; END = TEMP; }
        countNode++;
        cout << "\nAdded at end! Press enter to go back."; getch();
    }

    void insertAtPosition() {
        if (!START || countNode == 0) { insertAtBeginning(); return; }
        int pos;
        cout << "\nInsert after position (1 to " << countNode << "): ";
        cin >> pos;
        if (pos < 1 || pos > countNode) { cout << "\nInvalid!"; getch(); return; }

        string u, t;
        getData(u, t);
        SNode* TEMP = new SNode("TWEET" + to_string(TCNT++), u, t);
        SNode* curr = START;
        for (int i = 1; i < pos; i++) curr = curr->NEXT;

        TEMP->NEXT = curr->NEXT;
        curr->NEXT = TEMP;
        if (curr == END) END = TEMP;
        countNode++;
        cout << "\nInserted at position " <<pos<<"! Press enter to go back."; getch();
    }

    void deleteAtPosition() {
        if (!START) { cout << "\nEmpty!"; getch(); return; }
        int pos;
        cout << "\nDelete position (1 to " << countNode << "): ";
        cin >> pos;
        if (pos < 1 || pos > countNode) { cout << "\nInvalid!"; getch(); return; }

        SNode* TEMP = START;
        if (pos == 1) {
            START = START->NEXT;
            if (!START) END = nullptr;
            delete TEMP;
        } else {
            SNode* PREV = nullptr;
            for (int i = 1; i < pos; i++) { PREV = TEMP; TEMP = TEMP->NEXT; }
            PREV->NEXT = TEMP->NEXT;
            if (TEMP == END) END = PREV;
            delete TEMP;
        }
        countNode--;
        cout << "\nDeleted! Press enter to go back."; getch();
    }

    void showNodes() {
        system("cls");
        SNode* TEMP = START;
        while (TEMP) {
            cout << "[" << TEMP->ID << "] @" << TEMP->UNAME << ": " << TEMP->TWEET << endl;
            TEMP = TEMP->NEXT;
        }
        cout << "\nTotal: " << countNode << "\nPress any key..."; getch();
    }

    void MainMenu() {
        while (true) {
            system("cls");
            cout << "===== SINGLY LINKED LIST MODULE =====\n";
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
