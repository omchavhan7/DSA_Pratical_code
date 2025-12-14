#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int marks;
    Node* left;
    Node* right;

    Node(string n, int m) {
        name = n;
        marks = m;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;
    int roll;

    Node* insertNode(Node* node, string name, int marks) {
        if (node == nullptr)
            return new Node(name, marks);

        if (marks < node->marks)
            node->left = insertNode(node->left, name, marks);
        else
            node->right = insertNode(node->right, name, marks);

        return node;
    }

    void inorderAssign(Node* node) {
        if (!node) return;

        inorderAssign(node->left);

        cout << "Roll No. " << roll++
             << " | Name: " << node->name
             << " | Marks: " << node->marks << "\n";

        inorderAssign(node->right);
    }

public:
    BST() {
        root = nullptr;
        roll = 1;
    }

    void addStudent() {
        string name;
        int marks;

        cin.ignore();
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter marks: ";
        cin >> marks;

        root = insertNode(root, name, marks);
        cout << "Student added.\n";
    }

    void assignRollNumbers() {
        if (!root) {
            cout << "No student records found.\n";
            return;
        }
        roll = 1;
        cout << "\n===== ROLL NUMBER ASSIGNMENT =====\n";
        inorderAssign(root);
    }
};

int main() {
    BST tree;
    int choice;

    do {
        cout << "\n======= MENU =======\n";
        cout << "1. Add Student (Name + Marks)\n";
        cout << "2. Assign Roll Numbers\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: tree.addStudent(); break;
            case 2: tree.assignRollNumbers(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 3);

    return 0;
}
