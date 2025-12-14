#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = NULL;
    }
};

class SetList {
public:
    Node* head;

    SetList() {
        head = NULL;
    }

    void insert(string n) {
        Node* temp = new Node(n);
        temp->next = head;
        head = temp;
    }

    bool exists(string n) {
        Node* t = head;
        while (t) {
            if (t->name == n) return true;
            t = t->next;
        }
        return false;
    }

    void display() {
        if (!head) {
            cout << "No students.";
            return;
        }
        Node* t = head;
        while (t) {
            cout << t->name << " ";
            t = t->next;
        }
    }
};

int main() {
    SetList A, B;
    int totalStudents;
    int choice;

    cout << "Enter total number of students in class: ";
    cin >> totalStudents;

    do {
        cout << "\n\n--- MENU ---\n";
        cout << "1. Add student who likes Cricket (Set A)\n";
        cout << "2. Add student who likes Football (Set B)\n";
        cout << "3. Display students who like BOTH Cricket and Football\n";
        cout << "4. Display students who like EITHER Cricket or Football but NOT both\n";
        cout << "5. Display number of students who like NEITHER Cricket nor Football\n";
        cout << "6. Display Set A (Cricket)\n";
        cout << "7. Display Set B (Football)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "Enter name: ";
            cin >> name;
            A.insert(name);
        }

        else if (choice == 2) {
            string name;
            cout << "Enter name: ";
            cin >> name;
            B.insert(name);
        }

        else if (choice == 3) {
            SetList both;
            Node* t = A.head;
            while (t) {
                if (B.exists(t->name))
                    both.insert(t->name);
                t = t->next;
            }
            cout << "\nStudents who like BOTH: ";
            both.display();
        }

        else if (choice == 4) {
            SetList diff;
            Node* t = A.head;
            while (t) {
                if (!B.exists(t->name))
                    diff.insert(t->name);
                t = t->next;
            }
            t = B.head;
            while (t) {
                if (!A.exists(t->name))
                    diff.insert(t->name);
                t = t->next;
            }
            cout << "\nStudents who like EITHER but NOT BOTH: ";
            diff.display();
        }

        else if (choice == 5) {
            int neither = totalStudents;

            Node* tA = A.head;
            while (tA) {
                neither--;
                tA = tA->next;
            }

            Node* tB = B.head;
            while (tB) {
                if (!A.exists(tB->name))
                    neither--;
                tB = tB->next;
            }

            cout << "\nStudents who like NEITHER: " << neither;
        }

        else if (choice == 6) {
            cout << "\nSet A (Cricket): ";
            A.display();
        }

        else if (choice == 7) {
            cout << "\nSet B (Football): ";
            B.display();
        }

        else if (choice == 8) {
            cout << "Exiting...\n";
        }

        else {
            cout << "Invalid choice!";
        }

    } while (choice != 8);

    return 0;
}
