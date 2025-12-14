#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Node {
public:
    int PRN;
    string name;
    Node* next;

    Node(int p, string n) {
        PRN = p;
        name = n;
        next = NULL;
    }
};

class VertexClub {
private:
    Node* head;

public:
    VertexClub() {
        head = NULL;
    }

    void addPresident() {
        int prn;
        string name;

        cout << "Enter PRN: ";
        cin >> prn;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        Node* temp = new Node(prn, name);
        temp->next = head;
        head = temp;

        cout << "President added.\n";
    }

    void addSecretary() {
        int prn;
        string name;

        cout << "Enter PRN: ";
        cin >> prn;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        Node* temp = new Node(prn, name);

        if (head == NULL) {
            head = temp;
        } else {
            Node* p = head;
            while (p->next != NULL) p = p->next;
            p->next = temp;
        }

        cout << "Secretary added.\n";
    }

    void addMember() {
        int prn;
        string name;

        cout << "Enter PRN: ";
        cin >> prn;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        Node* temp = new Node(prn, name);

        if (head == NULL) head = temp;
        else {
            Node* p = head;
            while (p->next != NULL) p = p->next;
            p->next = temp;
        }

        cout << "Member added.\n";
    }

    void deletePresident() {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "President deleted.\n";
    }

    void deleteSecretary() {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Secretary deleted.\n";
            return;
        }

        Node* p = head;
        while (p->next->next != NULL) p = p->next;

        delete p->next;
        p->next = NULL;
        cout << "Secretary deleted.\n";
    }

    void deleteByPRN() {
        int prn;
        cout << "Enter PRN to delete: ";
        cin >> prn;

        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }

        if (head->PRN == prn) {
            deletePresident();
            return;
        }

        Node* p = head;
        while (p->next != NULL && p->next->PRN != prn)
            p = p->next;

        if (p->next == NULL) {
            cout << "PRN not found.\n";
            return;
        }

        Node* temp = p->next;
        p->next = temp->next;
        delete temp;

        cout << "Member deleted.\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }

        cout << "\nPRN\tName\n";
        Node* p = head;
        while (p != NULL) {
            cout << p->PRN << "\t" << p->name << endl;
            p = p->next;
        }
    }

    int countMembers() {
        int count = 0;
        Node* p = head;
        while (p != NULL) {
            count++;
            p = p->next;
        }
        return count;
    }

    void searchByPRN() {
        int prn;
        cout << "Enter PRN to search: ";
        cin >> prn;

        Node* p = head;
        while (p != NULL) {
            if (p->PRN == prn) {
                cout << "Member Found: " << p->name << endl;
                return;
            }
            p = p->next;
        }
        cout << "Member not found.\n";
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        cout << "List reversed.\n";
    }

    void sortByPRN() {
        if (head == NULL)
            return;

        for (Node* i = head; i->next != NULL; i = i->next) {
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (i->PRN > j->PRN) {
                    swap(i->PRN, j->PRN);
                    swap(i->name, j->name);
                }
            }
        }

        cout << "List sorted by PRN.\n";
    }

    void concatenate(VertexClub &L2) {
        if (head == NULL) {
            head = L2.head;
        } else {
            Node* p = head;
            while (p->next != NULL) p = p->next;
            p->next = L2.head;
        }

        L2.head = NULL;
        cout << "Lists concatenated.\n";
    }
};

int main() {
    VertexClub D1, D2;
    int choice;

    do {
        cout << "\n========== VERTEX CLUB MENU ==========\n";
        cout << "1. Add President\n";
        cout << "2. Add Secretary\n";
        cout << "3. Add Member\n";
        cout << "4. Delete President\n";
        cout << "5. Delete Secretary\n";
        cout << "6. Delete by PRN\n";
        cout << "7. Display Members\n";
        cout << "8. Count Members\n";
        cout << "9. Search by PRN\n";
        cout << "10. Reverse List\n";
        cout << "11. Sort by PRN\n";
        cout << "12. Concatenate Division 2 List\n";
        cout << "13. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: D1.addPresident(); break;
            case 2: D1.addSecretary(); break;
            case 3: D1.addMember(); break;
            case 4: D1.deletePresident(); break;
            case 5: D1.deleteSecretary(); break;
            case 6: D1.deleteByPRN(); break;
            case 7: D1.display(); break;
            case 8: cout << "Total Members: " << D1.countMembers() << endl; break;
            case 9: D1.searchByPRN(); break;
            case 10: D1.reverse(); break;
            case 11: D1.sortByPRN(); break;

            case 12:
                cout << "\nEnter 3 members for Division 2:\n";
                D2.addPresident();
                D2.addMember();
                D2.addSecretary();
                D1.concatenate(D2);
                break;

            case 13:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 13);

    getch();
    return 0;
}
