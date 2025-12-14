#include <iostream>
#include <stack>
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

    void mirror(Node* node) {
        if (!node) return;
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }

    int countLeafNodes(Node* node) {
        if (!node) return 0;
        if (!node->left && !node->right)
            return 1;
        return countLeafNodes(node->left) + countLeafNodes(node->right);
    }

public:
    BinaryTree() { root = nullptr; }

    // Create tree using level-wise input
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

            cout << "Enter left child of " << temp->data << " (-1 for no child): ";
            cin >> val;
            if (val != -1) {
                temp->left = new Node(val);
                q.push(temp->left);
            }

            cout << "Enter right child of " << temp->data << " (-1 for no child): ";
            cin >> val;
            if (val != -1) {
                temp->right = new Node(val);
                q.push(temp->right);
            }
        }
    }

    // Non-recursive inorder traversal
    void inorderNonRecursive() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }

        stack<Node*> st;
        Node* curr = root;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
        cout << "\n";
    }

    // Non-recursive preorder traversal
    void preorderNonRecursive() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* curr = st.top();
            st.pop();

            cout << curr->data << " ";

            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);
        }
        cout << "\n";
    }

    void displayLeafNodes() {
        cout << "Number of Leaf Nodes: " 
             << countLeafNodes(root) << "\n";
    }

    void mirrorImage() {
        mirror(root);
        cout << "Mirror image created successfully.\n";
    }
};

int main() {
    BinaryTree bt;
    int choice;

    do {
        cout << "\n=========== BINARY TREE MENU ===========\n";
        cout << "1. Create Binary Tree\n";
        cout << "2. Inorder Traversal (Non-Recursive)\n";
        cout << "3. Preorder Traversal (Non-Recursive)\n";
        cout << "4. Display Number of Leaf Nodes\n";
        cout << "5. Mirror Image of Tree\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bt.createTree(); break;
            case 2: bt.inorderNonRecursive(); break;
            case 3: bt.preorderNonRecursive(); break;
            case 4: bt.displayLeafNodes(); break;
            case 5: bt.mirrorImage(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
