#include <iostream>
using namespace std;

class Node {
public:
    int bit;
    Node* next;
    Node* prev;

    Node(int b) {
        bit = b;
        next = prev = NULL;
    }
};

class BinaryDLL {
public:
    Node* head;
    Node* tail;

    BinaryDLL() {
        head = tail = NULL;
    }

    void insertBit(int b) {
        Node* temp = new Node(b);
        if (!head) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void inputBinary() {
        head = tail = NULL;
        string s;
        cout << "Enter binary number: ";
        cin >> s;
        for (char c : s)
            insertBit(c - '0');
    }

    void display() {
        Node* t = head;
        while (t) {
            cout << t->bit;
            t = t->next;
        }
        cout << "\n";
    }

    BinaryDLL onesComplement() {
        BinaryDLL res;
        Node* t = head;
        while (t) {
            res.insertBit(t->bit == 0 ? 1 : 0);
            t = t->next;
        }
        return res;
    }

    void insertAtFront(int b) {
        Node* temp = new Node(b);
        if (!head) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    BinaryDLL twosComplement() {
        BinaryDLL oneC = onesComplement();
        BinaryDLL res;
        Node* t = oneC.tail;
        int carry = 1;

        while (t) {
            int sum = t->bit + carry;
            res.insertAtFront(sum % 2);
            carry = sum / 2;
            t = t->prev;
        }
        if (carry) res.insertAtFront(1);

        return res;
    }

    static BinaryDLL add(BinaryDLL& A, BinaryDLL& B) {
        BinaryDLL result;
        Node* p = A.tail;
        Node* q = B.tail;
        int carry = 0;

        while (p || q || carry) {
            int x = (p ? p->bit : 0);
            int y = (q ? q->bit : 0);
            int sum = x + y + carry;
            result.insertAtFront(sum % 2);
            carry = sum / 2;
            if (p) p = p->prev;
            if (q) q = q->prev;
        }
        return result;
    }
};

int main() {
    BinaryDLL B1, B2, result;
    int choice;

    do {
        cout << "\n--- Binary DLL Menu ---\n";
        cout << "1. Enter Binary Number 1\n";
        cout << "2. Display 1's Complement of Number 1\n";
        cout << "3. Display 2's Complement of Number 1\n";
        cout << "4. Enter Binary Number 2\n";
        cout << "5. Add Number 1 and Number 2\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            B1.inputBinary();
            cout << "Number 1: ";
            B1.display();
            break;

        case 2: {
            cout << "1's Complement: ";
            BinaryDLL oneC = B1.onesComplement();
            oneC.display();
            break;
        }

        case 3: {
            cout << "2's Complement: ";
            BinaryDLL twoC = B1.twosComplement();
            twoC.display();
            break;
        }

        case 4:
            B2.inputBinary();
            cout << "Number 2: ";
            B2.display();
            break;

        case 5:
            result = BinaryDLL::add(B1, B2);
            cout << "Addition Result: ";
            result.display();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
