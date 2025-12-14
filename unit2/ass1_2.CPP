#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string seat;
    bool booked;
    Node* next;
    Node* prev;

    Node(string s) {
        seat = s;
        booked = false;
        next = prev = NULL;
    }
};

class GalaxyMultiplex {
private:
    Node* rows[8];
    char rowLetter[8] = {'A','B','C','D','E','F','G','H'};

public:
    GalaxyMultiplex() {
        for (int r = 0; r < 8; r++) {
            rows[r] = NULL;
            Node* last = NULL;

            for (int s = 1; s <= 8; s++) {
                string seatName = string(1, rowLetter[r]) + to_string(s);
                Node* temp = new Node(seatName);

                if (!rows[r]) {
                    rows[r] = temp;
                    last = temp;
                } else {
                    last->next = temp;
                    temp->prev = last;
                    last = temp;
                }

                if (s == 8) {
                    last->next = rows[r];
                    rows[r]->prev = last;
                }
            }
        }
    }

    void showLayout() {
        cout << "\nSeat Layout (O = empty, X = booked)\n";
        for (int r = 0; r < 8; r++) {
            cout << "\nRow " << rowLetter[r] << ": ";
            Node* t = rows[r];
            do {
                cout << t->seat << "(" << (t->booked ? "X" : "O") << ") ";
                t = t->next;
            } while (t != rows[r]);
        }
        cout << "\n";
    }

    void displayAvailable() {
        cout << "\nAvailable Seats:\n";
        for (int r = 0; r < 8; r++) {
            cout << "Row " << rowLetter[r] << ": ";
            Node* t = rows[r];
            do {
                if (!t->booked)
                    cout << t->seat << " ";
                t = t->next;
            } while (t != rows[r]);
            cout << "\n";
        }
    }

    Node* findSeat(string seat) {
        char row = seat[0];
        int r = row - 'A';
        Node* t = rows[r];
        do {
            if (t->seat == seat) return t;
            t = t->next;
        } while (t != rows[r]);
        return NULL;
    }

    void bookSeats() {
        int n;
        cout << "How many seats to book? ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            string seat;
            cout << "Enter seat (ex: A3): ";
            cin >> seat;

            Node* t = findSeat(seat);
            if (!t) cout << "Invalid seat!\n";
            else if (t->booked) cout << "Already booked!\n";
            else {
                t->booked = true;
                cout << "Booked " << seat << "\n";
            }
        }
    }

    void cancelSeats() {
        int n;
        cout << "How many seats to cancel? ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            string seat;
            cout << "Enter seat to cancel: ";
            cin >> seat;

            Node* t = findSeat(seat);
            if (!t) cout << "Invalid seat!\n";
            else if (!t->booked) cout << "Seat is not booked!\n";
            else {
                t->booked = false;
                cout << "Cancelled " << seat << "\n";
            }
        }
    }

    void showBookedSeats() {
        cout << "\nBooked Seats: ";
        for (int r = 0; r < 8; r++) {
            Node* t = rows[r];
            do {
                if (t->booked)
                    cout << t->seat << " ";
                t = t->next;
            } while (t != rows[r]);
        }
        cout << "\n";
    }

    void countSeats() {
        int booked = 0, available = 0;
        for (int r = 0; r < 8; r++) {
            Node* t = rows[r];
            do {
                if (t->booked) booked++;
                else available++;
                t = t->next;
            } while (t != rows[r]);
        }
        cout << "\nTotal Seats: 64\nBooked: " << booked << "\nAvailable: " << available << "\n";
    }

    void resetAll() {
        for (int r = 0; r < 8; r++) {
            Node* t = rows[r];
            do {
                t->booked = false;
                t = t->next;
            } while (t != rows[r]);
        }
        cout << "All seats reset.\n";
    }

    void suggestBestSeats() {
        string bestRows = "DE"; 
        cout << "\nBest seat suggestions: ";

        for (char row : bestRows) {
            int r = row - 'A';
            Node* t = rows[r];
            do {
                if (!t->booked)
                    cout << t->seat << " ";
                t = t->next;
            } while (t != rows[r]);
        }
        cout << "\n";
    }
};

int main() {
    GalaxyMultiplex g;
    int ch;

    do {
        cout << "\n--- Galaxy Multiplex Menu ---\n";
        cout << "1. Show Seat Layout\n";
        cout << "2. Display Available Seats\n";
        cout << "3. Book Seats\n";
        cout << "4. Cancel Seats\n";
        cout << "5. Show Booked Seats\n";
        cout << "6. Count Booked/Available Seats\n";
        cout << "7. Reset All Bookings\n";
        cout << "8. Suggest Best Seats\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case 1: g.showLayout(); break;
        case 2: g.displayAvailable(); break;
        case 3: g.bookSeats(); break;
        case 4: g.cancelSeats(); break;
        case 5: g.showBookedSeats(); break;
        case 6: g.countSeats(); break;
        case 7: g.resetAll(); break;
        case 8: g.suggestBestSeats(); break;
        case 9: break;
        default: cout << "Invalid choice!\n";
        }
    } while (ch != 9);

    return 0;
}
