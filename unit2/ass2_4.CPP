#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = next = NULL;
    }
};

class DoublyList {
public:
    Node* head;

    DoublyList() {
        head = NULL;
    }

    void insertBegin(int x) {
        Node* temp = new Node(x);
        if (!head)
            head = temp;
        else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
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
            temp->prev = t;
        }
    }

    void insertPos(int x, int pos) {
        if (pos == 1) {
            insertBegin(x);
            return;
        }

        Node* t = head;
        for (int i = 1; i < pos - 1 && t; i++)
            t = t->next;

        if (!t) {
            cout << "Invalid position\n";
            return;
        }

        Node* temp = new Node(x);
        temp->next = t->next;
        temp->prev = t;

        if (t->next)
            t->next->prev = temp;

        t->next = temp;
    }

    void deleteBegin() {
        if (!head) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
    }

    void deleteEnd() {
        if (!head) {
            cout << "List empty\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }
        Node* t = head;
        while (t->next)
            t = t->next;

        t->prev->next = NULL;
        delete t;
    }

    void deletePos(int pos) {
        if (!head) {
            cout << "List empty\n";
            return;
        }

        if (pos == 1) {
            deleteBegin();
            return;
        }

        Node* t = head;
        for (int i = 1; i < pos && t; i++)
            t = t->next;

        if (!t) {
            cout << "Invalid position\n";
            return;
        }

        if (t->prev) t->prev->next = t->next;
        if (t->next) t->next->prev = t->prev;

        delete t;
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
};

int main() {
    DoublyList dl;
    int ch, val, pos;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            dl.insertBegin(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            dl.insertEnd(val);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> val;
            cout << "Enter position: ";
            cin >> pos;
            dl.insertPos(val, pos);
            break;

        case 4:
            dl.deleteBegin();
            break;

        case 5:
            dl.deleteEnd();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> pos;
            dl.deletePos(pos);
            break;

        case 7:
            dl.display();
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (ch != 8);

    return 0;
}
