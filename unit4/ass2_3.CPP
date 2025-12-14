#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int empID;
    string name;
    float salary;
    Node* left;
    Node* right;

    Node(int id, string n, float s) {
        empID = id;
        name = n;
        salary = s;
        left = right = nullptr;
    }
};

class EmployeeBST {
private:
    Node* root;

    Node* insertNode(Node* node, int id, string name, float salary) {
        if (node == nullptr)
            return new Node(id, name, salary);

        if (id < node->empID)
            node->left = insertNode(node->left, id, name, salary);
        else
            node->right = insertNode(node->right, id, name, salary);

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr) return;

        inorder(node->left);
        cout << "EmpID: " << node->empID
             << " | Name: " << node->name
             << " | Salary: " << node->salary << "\n";
        inorder(node->right);
    }

    Node* searchNode(Node* node, int id) {
        if (node == nullptr) return nullptr;
        if (node->empID == id) return node;

        if (id < node->empID)
            return searchNode(node->left, id);
        else
            return searchNode(node->right, id);
    }

public:
    EmployeeBST() {
        root = nullptr;
    }

    void insert() {
        int id;
        string name;
        float salary;

        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Salary: ";
        cin >> salary;

        root = insertNode(root, id, name, salary);
        cout << "Employee Added Successfully.\n";
    }

    void search() {
        int id;
        cout << "Enter Employee ID to search: ";
        cin >> id;

        Node* emp = searchNode(root, id);
        if (emp == nullptr)
            cout << "Employee with ID " << id << " not found.\n";
        else {
            cout << "\n--- Employee Found ---\n";
            cout << "EmpID: " << emp->empID
                 << " | Name: " << emp->name
                 << " | Salary: " << emp->salary << "\n";
        }
    }

    void sortAscending() {
        if (root == nullptr) {
            cout << "No employee records found.\n";
            return;
        }
        cout << "\n--- Employee Records (Sorted by EmpID ASC) ---\n";
        inorder(root);
    }
};

int main() {
    EmployeeBST bst;
    int choice;

    do {
        cout << "\n========== EMPLOYEE MENU ==========\n";
        cout << "1. Insert Employee Record\n";
        cout << "2. Search Employee by ID\n";
        cout << "3. Sort & Display All Employees (Ascending Emp-ID)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: bst.insert(); break;
            case 2: bst.search(); break;
            case 3: bst.sortAscending(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 4);

    return 0;
}
