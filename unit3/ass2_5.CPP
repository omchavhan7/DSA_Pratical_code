#include <iostream>
#include <string.h>
#include <iomanip>
#include <ctime>
using namespace std;

string getTimeStamp() {
    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt)-1] = '\0';
    return dt;
}

class Node {
public:
    int callID;
    string name;
    string issue;
    string priority;
    string timestamp;
    Node* next;

    Node(int id, string n, string i, string p) {
        callID = id;
        name = n;
        issue = i;
        priority = p;
        timestamp = getTimeStamp();
        next = nullptr;
    }
};

class CallCenter {
private:
    Node* front;
    Node* rear;
    Node* servedFront;
    Node* servedRear;
    int nextID = 1001;

public:
    CallCenter() {
        front = rear = nullptr;
        servedFront = servedRear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueueCall() {
        string name, issue, priority;

        cin.ignore();
        cout << "Enter Caller Name: ";
        getline(cin, name);

        cout << "Enter Issue: ";
        getline(cin, issue);

        cout << "Priority (VIP / Normal): ";
        getline(cin, priority);

        Node* newNode = new Node(nextID++, name, issue, priority);

        if (priority == "VIP" || priority == "vip") {
            newNode->next = front;
            front = newNode;
            if (rear == nullptr) rear = newNode;
        } else {
            if (isEmpty()) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        cout << "Call Enqueued Successfully. Call ID: " << newNode->callID << "\n";
    }

    void recordServed(Node* p) {
        Node* newNode = new Node(*p);
        newNode->next = nullptr;

        if (servedFront == nullptr) {
            servedFront = servedRear = newNode;
        } else {
            servedRear->next = newNode;
            servedRear = newNode;
        }
    }

    void dequeueCall(int agent) {
        if (isEmpty()) {
            cout << "No calls waiting. Agents are idle.\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) rear = nullptr;

        cout << "\n--- Call Assigned to Agent " << agent << " ---\n";
        displaySingle(temp);

        recordServed(temp);
        delete temp;
    }

    void displaySingle(Node* p) {
        cout << left
             << setw(10) << "CallID"
             << setw(18) << "Name"
             << setw(10) << "Priority"
             << setw(20) << "Issue"
             << setw(25) << "Time Stamp"
             << "\n";

        cout << setw(10) << p->callID
             << setw(18) << p->name
             << setw(10) << p->priority
             << setw(20) << p->issue
             << setw(25) << p->timestamp << "\n";
    }

    void showWaiting() {
        if (isEmpty()) {
            cout << "No calls waiting.\n";
            return;
        }

        cout << "\n--- Waiting Calls ---\n";

        Node* temp = front;
        while (temp != nullptr) {
            displaySingle(temp);
            temp = temp->next;
        }
    }

    void showServed() {
        if (servedFront == nullptr) {
            cout << "No served call records.\n";
            return;
        }

        cout << "\n--- Served Calls ---\n";

        Node* temp = servedFront;
        while (temp != nullptr) {
            displaySingle(temp);
            temp = temp->next;
        }
    }

    void searchCall() {
        int id;
        cout << "Enter Call ID to search: ";
        cin >> id;

        Node* temp = front;
        while (temp != nullptr) {
            if (temp->callID == id) {
                cout << "Call Found (Waiting)\n";
                displaySingle(temp);
                return;
            }
            temp = temp->next;
        }

        temp = servedFront;
        while (temp != nullptr) {
            if (temp->callID == id) {
                cout << "Call Found (Served)\n";
                displaySingle(temp);
                return;
            }
            temp = temp->next;
        }

        cout << "No call found with ID " << id << "\n";
    }
};

int main() {
    CallCenter cc;
    int choice;

    do {
        cout << "\n========= ADVANCED CALL CENTER MENU =========\n";
        cout << "1. Enqueue New Call\n";
        cout << "2. Serve Call (Agent 1)\n";
        cout << "3. Serve Call (Agent 2)\n";
        cout << "4. Display Waiting Calls\n";
        cout << "5. Display Served Calls\n";
        cout << "6. Search Call by ID\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: cc.enqueueCall(); break;
            case 2: cc.dequeueCall(1); break;
            case 3: cc.dequeueCall(2); break;
            case 4: cc.showWaiting(); break;
            case 5: cc.showServed(); break;
            case 6: cc.searchCall(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}
