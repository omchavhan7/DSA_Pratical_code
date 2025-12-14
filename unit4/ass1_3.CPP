#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data)
            node->left = insertNode(node->left, val);
        else
            node->right = insertNode(node->right, val);

        return node;
    }

    int findMin(Node* node) {
        if (node == nullptr) {
            cout << "Tree is empty.\n";
            return -1;
        }
        while (node->left != nullptr)
            node = node->left;
        return node->data;
    }

    int findMax(Node* node) {
        if (node == nullptr) {
            cout << "Tree is empty.\n";
            return -1;
        }
        while (node->right != nullptr)
            node = node->right;
        return node->data;
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insertNode(root, val);
    }

    void findMinimum() {
        int minVal = findMin(root);
        if (minVal != -1)
            cout << "Minimum value: " << minVal << "\n";
    }

    void findMaximum() {
        int maxVal = findMax(root);
        if (maxVal != -1)
            cout << "Maximum value: " << maxVal << "\n";
    }

    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << "\n";
    }
};

int main() {
    BST tree;
    int choice, value;

    do {
        cout << "\n========== BST MENU ==========\n";
        cout << "1. Insert Node\n";
        cout << "2. Find Minimum\n";
        cout << "3. Find Maximum\n";
        cout << "4. Display Inorder\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                tree.insert(value);
                break;

            case 2:
                tree.findMinimum();
                break;

            case 3:
                tree.findMaximum();
                break;

            case 4:
                tree.displayInorder();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
