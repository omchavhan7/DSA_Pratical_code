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

class BinaryTree {
private:
    Node* root;

    void inorderRec(Node* node) {
        if (node == nullptr) return;
        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }

    void preorderRec(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    int leafCount(Node* node) {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr)
            return 1;
        return leafCount(node->left) + leafCount(node->right);
    }

    void mirrorTree(Node* node) {
        if (node == nullptr) return;
        swap(node->left, node->right);
        mirrorTree(node->left);
        mirrorTree(node->right);
    }

public:
    BinaryTree() { root = nullptr; }

    // Create tree level-wise
    void createTree() {
        int val;
        cout << "Enter root value (-1 for no root): ";
        cin >> val;

        if (val == -1) {
            root = nullptr;
            return;
        }

        root = new Node(val);
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            cout << "Enter left child of " << temp->data << " (-1 for none): ";
            cin >> val;
            if (val != -1) {
                temp->left = new Node(val);
                q.push(temp->left);
            }

            cout << "Enter right child of " << temp->data << " (-1 for none): ";
            cin >> val;
            if (val != -1) {
                temp->right = new Node(val);
                q.push(temp->right);
            }
        }
    }

    void inorder() {
        cout << "Inorder Traversal: ";
        inorderRec(root);
        cout << "\n";
    }

    void preorder() {
        cout << "Preorder Traversal: ";
        preorderRec(root);
        cout << "\n";
    }

    void displayLeafNodes() {
        cout << "Number of Leaf Nodes: " << leafCount(root) << "\n";
    }

    void mirrorImage() {
        mirrorTree(root);
        cout << "Mirror Image Created Successfully.\n";
    }
};

int main() {
    BinaryTree bt;
    int choice;

    do {
        cout << "\n=========== BINARY TREE MENU ===========\n";
        cout << "1. Create Binary Tree\n";
        cout << "2. Recursive Inorder Traversal\n";
        cout << "3. Recursive Preorder Traversal\n";
        cout << "4. Count Leaf Nodes\n";
        cout << "5. Mirror Image\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bt.createTree(); break;
            case 2: bt.inorder(); break;
            case 3: bt.preorder(); break;
            case 4: bt.displayLeafNodes(); break;
            case 5: bt.mirrorImage(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n"; break;
        }

    } while (choice != 6);

    return 0;
}
