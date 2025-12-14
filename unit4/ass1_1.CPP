#include <iostream>
#include <queue>
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

    Node* findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int val) {
        if (node == nullptr)
            return node;

        if (val < node->data)
            node->left = deleteNode(node->left, val);

        else if (val > node->data)
            node->right = deleteNode(node->right, val);

        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
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

public:
    BST() { root = nullptr; }

    void create(int val) {
        if (root == nullptr)
            root = new Node(val);
        else
            cout << "Tree already created. Use Insert.\n";
    }

    void insert(int val) {
        root = insertNode(root, val);
    }

    void deleteValue(int val) {
        root = deleteNode(root, val);
    }

    void levelOrder() {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        cout << "Levelwise Display: ";
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left != nullptr) 
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(temp->right);
        }
        cout << "\n";
    }
};
    
int main() {
    BST tree;
    int choice, val;

    do {
        cout << "\n========== BST MENU ==========\n";
        cout << "1. Create Tree (First Node)\n";
        cout << "2. Insert Node\n";
        cout << "3. Delete Node\n";
        cout << "4. Levelwise Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter root value: ";
                cin >> val;
                tree.create(val);
                break;

            case 2:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insert(val);
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                tree.deleteValue(val);
                break;

            case 4:
                tree.levelOrder();
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
