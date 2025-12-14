#include <iostream>
using namespace std;

class Node {
public:
    int coeff;
    int pow;
    Node* next;

    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

class Polynomial {
public:
    Node* head;

    Polynomial() {
        head = NULL;
    }

    void insert(int c, int p) {
        Node* temp = new Node(c, p);
        if (!head)
            head = temp;
        else {
            Node* t = head;
            while (t->next)
                t = t->next;
            t->next = temp;
        }
    }

    void create() {
        head = NULL;
        int n, c, p;
        cout << "Enter number of terms: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Coefficient: ";
            cin >> c;
            cout << "Power: ";
            cin >> p;
            insert(c, p);
        }
    }

    void display() {
        if (!head) {
            cout << "Polynomial is empty\n";
            return;
        }

        Node* t = head;
        while (t) {
            cout << t->coeff << "x^" << t->pow;
            if (t->next) cout << " + ";
            t = t->next;
        }
        cout << "\n";
    }

    static Polynomial add(Polynomial& A, Polynomial& B) {
        Polynomial R;
        Node* p = A.head;
        Node* q = B.head;

        while (p && q) {
            if (p->pow == q->pow) {
                R.insert(p->coeff + q->coeff, p->pow);
                p = p->next;
                q = q->next;
            }
            else if (p->pow > q->pow) {
                R.insert(p->coeff, p->pow);
                p = p->next;
            }
            else {
                R.insert(q->coeff, q->pow);
                q = q->next;
            }
        }

        while (p) {
            R.insert(p->coeff, p->pow);
            p = p->next;
        }

        while (q) {
            R.insert(q->coeff, q->pow);
            q = q->next;
        }

        return R;
    }
};

int main() {
    Polynomial P1, P2, Sum;
    int choice;

    do {
        cout << "\n--- Polynomial Menu ---\n";
        cout << "1. Create Polynomial 1\n";
        cout << "2. Create Polynomial 2\n";
        cout << "3. Display Polynomial 1\n";
        cout << "4. Display Polynomial 2\n";
        cout << "5. Add Polynomials\n";
        cout << "6. Display Result\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Polynomial 1:\n";
            P1.create();
            break;

        case 2:
            cout << "Enter Polynomial 2:\n";
            P2.create();
            break;

        case 3:
            cout << "Polynomial 1: ";
            P1.display();
            break;

        case 4:
            cout << "Polynomial 2: ";
            P2.display();
            break;

        case 5:
            Sum = Polynomial::add(P1, P2);
            cout << "Polynomials Added!\n";
            break;

        case 6:
            cout << "Sum: ";
            Sum.display();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}
