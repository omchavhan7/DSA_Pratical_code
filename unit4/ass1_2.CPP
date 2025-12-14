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

    int countNodes(Node* node) {
        if (node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int treeHeight(Node* node) {
        if (node == nullptr) return 0;

        int lh = treeHeight(node->left);
        int rh = treeHeight(node->right);

        return 1 + max(lh, rh);
    }

    void mirrorTree(Node* node) {
        if (node == nullptr) return;

        swap(node->left, node->right);

        mirrorTree(node->left);
        mirrorTree(node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insertNode(root, val);
    }

    void displayLevelOrder() {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        cout << "\nLevel Order: ";
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << "\n";
    }

    void countTotalNodes() {
        cout << "Total Nodes in BST: " << countNodes(root) << "\n";
    }

    void computeHeight() {
        cout << "Height of BST: " << treeHeight(root) << "\n";
    }

    void mirrorImage() {
        mirrorTree(root);
        cout << "Mirror Image Created Successfully.\n";
    }
};

int main() {
    BST tree;
    int choice, value;

    do {
        cout << "\n========== BST MENU ==========\n";
        cout << "1. Insert Node\n";
        cout << "2. Count Total Nodes\n";
        cout << "3. Compute Height of BST\n";
        cout << "4. Create Mirror Image\n";
        cout << "5. Levelwise Display\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                tree.insert(value);
                break;

            case 2:
                tree.countTotalNodes();
                break;

            case 3:
                tree.computeHeight();
                break;

            case 4:
                tree.mirrorImage();
                break;

            case 5:
                tree.displayLevelOrder();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
