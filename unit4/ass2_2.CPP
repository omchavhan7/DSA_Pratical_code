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
        if (!node) return new Node(val);

        if (val < node->data)
            node->left = insertNode(node->left, val);
        else
            node->right = insertNode(node->right, val);

        return node;
    }

    Node* findMin(Node* node) {
        while (node->left)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int val) {
        if (!node) return node;

        if (val < node->data)
            node->left = deleteNode(node->left, val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    bool searchNode(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data)
            return searchNode(node->left, val);
        return searchNode(node->right, val);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() { root = nullptr; }

    void insert(int val) { root = insertNode(root, val); }

    void deleteKey(int val) {
        root = deleteNode(root, val);
    }

    void find(int val) {
        if (searchNode(root, val))
            cout << val << " found in BST.\n";
        else
            cout << val << " not found in BST.\n";
    }

    void show() {
        if (!root) {
            cout << "BST is empty.\n";
            return;
        }
        cout << "BST (Inorder): ";
        inorder(root);
        cout << "\n";
    }
};

int main() {
    BST tree;
    int choice, value;

    do {
        cout << "\n========== BST MENU ==========\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Find/Search\n";
        cout << "4. Show (Inorder Traversal)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.deleteKey(value);
                break;

            case 3:
                cout << "Enter value to find: ";
                cin >> value;
                tree.find(value);
                break;

            case 4:
                tree.show();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while(choice != 5);

    return 0;
}
