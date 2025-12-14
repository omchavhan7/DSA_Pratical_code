#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertEnd(int x) {
        Node* temp = new Node(x);
        if (!head)
            head = temp;
        else {
            Node* t = head;
            while (t->next)
                t = t->next;
            t->next = temp;
        }
    }

    void display() {
        if (!head) {
            cout << "List empty\n";
            return;
        }
        Node* t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }

    void frontBackSplit(LinkedList& front, LinkedList& back) {
        if (!head) {
            front.head = NULL;
            back.head = NULL;
            return;
        }
        if (!head->next) {
            front.head = head;
            back.head = NULL;
            return;
        }

        Node* slow = head;
        Node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        front.head = head;
        back.head = slow->next;
        slow->next = NULL;
    }
};

int main() {
    LinkedList L, Front, Back;
    int ch, val;

    do {
        cout << "\n--- Front Back Split Menu ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Display List\n";
        cout << "3. Split List into Front and Back\n";
        cout << "4. Display Front List\n";
        cout << "5. Display Back List\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            L.insertEnd(val);
            break;

        case 2:
            cout << "Original List: ";
            L.display();
            break;

        case 3:
            Front = LinkedList();
            Back = LinkedList();
            L.frontBackSplit(Front, Back);
            cout << "List Split Successfully\n";
            break;

        case 4:
            cout << "Front List: ";
            Front.display();
            break;

        case 5:
            cout << "Back List: ";
            Back.display();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (ch != 6);

    return 0;
}
