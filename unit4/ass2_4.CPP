#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string productName;
    string productCode;
    float price;
    int quantity;
    string dateReceived;
    string expiryDate;
    Node* left;
    Node* right;

    Node(string code, string name, float p, int q, string dR, string eD) {
        productCode = code;
        productName = name;
        price = p;
        quantity = q;
        dateReceived = dR;
        expiryDate = eD;
        left = right = nullptr;
    }
};

class InventoryBST {
private:
    Node* root;

    Node* insertNode(Node* node, string code, string name, float price,
                     int qty, string dR, string eD) {
        if (node == nullptr)
            return new Node(code, name, price, qty, dR, eD);

        if (name < node->productName)
            node->left = insertNode(node->left, code, name, price, qty, dR, eD);
        else
            node->right = insertNode(node->right, code, name, price, qty, dR, eD);

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr) return;

        inorder(node->left);

        cout << "\nProduct Name : " << node->productName
             << "\nProduct Code : " << node->productCode
             << "\nPrice        : " << node->price
             << "\nQuantity     : " << node->quantity
             << "\nReceived On  : " << node->dateReceived
             << "\nExpiry Date  : " << node->expiryDate
             << "\n----------------------------------";

        inorder(node->right);
    }

    bool isExpired(const string& expiryDate) {
        return true;
    }

    void listExpiredPreorder(Node* node) {
        if (node == nullptr) return;

        if (isExpired(node->expiryDate)) {
            cout << "\n[EXPIRED PRODUCT]\n";
            cout << "Name        : " << node->productName << "\n";
            cout << "Code        : " << node->productCode << "\n";
            cout << "Expiry Date : " << node->expiryDate << "\n";
            cout << "----------------------------------\n";
        }

        listExpiredPreorder(node->left);
        listExpiredPreorder(node->right);
    }

public:
    InventoryBST() { root = nullptr; }

    void insertProduct() {
        string code, name, dateReceived, expiryDate;
        float price;
        int quantity;

        cin.ignore();
        cout << "Enter Product Code: ";
        getline(cin, code);

        cout << "Enter Product Name: ";
        getline(cin, name);

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
        cin.ignore();

        cout << "Enter Date Received (DD/MM/YYYY): ";
        getline(cin, dateReceived);

        cout << "Enter Expiration Date (DD/MM/YYYY): ";
        getline(cin, expiryDate);

        root = insertNode(root, code, name, price, quantity, dateReceived, expiryDate);
        cout << "Product Added Successfully.\n";
    }

    void displayInventory() {
        if (root == nullptr) {
            cout << "Inventory is empty.\n";
            return;
        }
        cout << "\n----- INVENTORY (Sorted by Name – Inorder) -----\n";
        inorder(root);
        cout << "\n--------------------------------------\n";
    }

    void displayExpired() {
        if (root == nullptr) {
            cout << "Inventory is empty.\n";
            return;
        }
        cout << "\n----- EXPIRED PRODUCTS (Preorder Traversal) -----\n";
        listExpiredPreorder(root);
    }
};

int main() {
    InventoryBST shop;
    int choice;

    do {
        cout << "\n========== PRODUCT INVENTORY MENU ==========\n";
        cout << "1. Insert New Product\n";
        cout << "2. Display All Products (Inorder)\n";
        cout << "3. List Expired Products (Preorder)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: shop.insertProduct(); break;
            case 2: shop.displayInventory(); break;
            case 3: shop.displayExpired(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while(choice != 4);

    return 0;
}
