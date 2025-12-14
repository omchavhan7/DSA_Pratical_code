#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

class DoublyList {
public:
    Node* head;

    DoublyList() {
        head = NULL;
    }

    void insert(int val) {
        Node* temp = new Node(val);
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

    void create() {
        head = NULL;
        int n, x;
        cout << "Enter number of elements: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Enter value: ";
            cin >> x;
            insert(x);
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }

    void bubbleSort() {
        if (!head) return;

        bool swapped;
        do {
            swapped = false;
            Node* t = head;

            while (t->next) {
                if (t->data > t->next->data) {
                    int temp = t->data;
                    t->data = t->next->data;
                    t->next->data = temp;
                    swapped = true;
                }
                t = t->next;
            }

        } while (swapped);
    }
};

int main() {
    DoublyList dl;
    int choice;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Create List\n";
        cout << "2. Display List\n";
        cout << "3. Bubble Sort List\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            dl.create();
            break;
        case 2:
            dl.display();
            break;
        case 3:
            dl.bubbleSort();
            cout << "List sorted using Bubble Sort\n";
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
