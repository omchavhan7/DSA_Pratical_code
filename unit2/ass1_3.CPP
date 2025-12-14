#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int start;
    int end;
    Node* next;

    Node(int s, int e) {
        start = s;
        end = e;
        next = NULL;
    }
};

class AppointmentList {
private:
    Node* head;
    int dayStart = 9;
    int dayEnd = 17;
    int minDur = 1;
    int maxDur = 3;

public:
    AppointmentList() {
        head = NULL;
    }

    void display() {
        cout << "\nCurrent Appointments:\n";
        Node* t = head;
        while (t) {
            cout << t->start << ":00 - " << t->end << ":00\n";
            t = t->next;
        }
        cout << "\nAvailable Slots:\n";

        int current = dayStart;
        t = head;
        while (t) {
            if (current < t->start)
                cout << current << ":00 - " << t->start << ":00\n";
            current = t->end;
            t = t->next;
        }
        if (current < dayEnd)
            cout << current << ":00 - " << dayEnd << ":00\n";
    }

    bool isAvailable(int s, int e) {
        if (s < dayStart || e > dayEnd) return false;
        if (e - s < minDur || e - s > maxDur) return false;

        Node* t = head;
        while (t) {
            if (!(e <= t->start || s >= t->end))
                return false;
            t = t->next;
        }
        return true;
    }

    void book() {
        int s, e;
        cout << "Enter start time: ";
        cin >> s;
        cout << "Enter end time: ";
        cin >> e;

        if (!isAvailable(s, e)) {
            cout << "Cannot book this slot.\n";
            return;
        }

        Node* temp = new Node(s, e);

        if (!head || s < head->start) {
            temp->next = head;
            head = temp;
            return;
        }

        Node* t = head;
        while (t->next && t->next->start < s)
            t = t->next;

        temp->next = t->next;
        t->next = temp;
    }

    void cancel() {
        int s, e;
        cout << "Enter start time: ";
        cin >> s;
        cout << "Enter end time: ";
        cin >> e;

        if (!head) {
            cout << "No appointments.\n";
            return;
        }

        if (head->start == s && head->end == e) {
            Node* del = head;
            head = head->next;
            delete del;
            cout << "Cancelled.\n";
            return;
        }

        Node* t = head;
        while (t->next && !(t->next->start == s && t->next->end == e))
            t = t->next;

        if (!t->next) {
            cout << "Appointment not found.\n";
            return;
        }

        Node* del = t->next;
        t->next = del->next;
        delete del;
        cout << "Cancelled.\n";
    }

    void sortByData() {
        if (!head) return;

        for (Node* i = head; i; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->start > j->start) {
                    swap(i->start, j->start);
                    swap(i->end, j->end);
                }
            }
        }
    }

    void sortByPointer() {
        if (!head) return;

        Node* sorted = NULL;

        while (head) {
            Node* curr = head;
            head = head->next;
            curr->next = NULL;

            if (!sorted || curr->start < sorted->start) {
                curr->next = sorted;
                sorted = curr;
            } else {
                Node* t = sorted;
                while (t->next && t->next->start < curr->start)
                    t = t->next;
                curr->next = t->next;
                t->next = curr;
            }
        }
        head = sorted;
    }
};

int main() {
    AppointmentList a;
    int ch;

    do {
        cout << "\n--- Appointment Scheduler ---\n";
        cout << "1. Display Available Slots\n";
        cout << "2. Book Appointment\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Sort by Data Swapping\n";
        cout << "5. Sort by Pointer Manipulation\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: a.display(); break;
            case 2: a.book(); break;
            case 3: a.cancel(); break;
            case 4: a.sortByData(); cout << "Sorted.\n"; break;
            case 5: a.sortByPointer(); cout << "Sorted.\n"; break;
            case 6: break;
            default: cout << "Invalid choice.\n";
        }
    } while (ch != 6);

    return 0;
}
