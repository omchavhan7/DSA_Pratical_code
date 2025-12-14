#include <iostream>
#include <queue>
#include <string.h>
#include <iomanip>
#include <ctime>
using namespace std;

string getTimeStamp() {
    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt)-1] = '\0';
    return dt;
}

struct Passenger {
    int ticketID;
    string name;
    int age;
    string destination;
    string travelClass;
    string timestamp;

    Passenger(int id=0, string n="", int a=0, string d="", string t="") {
        ticketID = id;
        name = n;
        age = a;
        destination = d;
        travelClass = t;
        timestamp = getTimeStamp();
    }
};

class TicketQueue {
private:
    queue<Passenger> q;
    queue<Passenger> served;
    int nextID = 1001;

public:
    void insertPassenger() {
        string name, destination, travelClass;
        int age;

        cin.ignore();
        cout << "Enter passenger name: ";
        getline(cin, name);

        cout << "Enter age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter destination: ";
        getline(cin, destination);

        cout << "Enter travel class (General/AC/First): ";
        getline(cin, travelClass);

        Passenger p(nextID++, name, age, destination, travelClass);
        q.push(p);

        cout << "Passenger Added. Ticket ID: " << p.ticketID << "\n";
    }

    void displayFront() {
        if (q.empty()) {
            cout << "No passengers waiting.\n";
            return;
        }
        Passenger p = q.front();
        displayPassenger(p);
    }

    void servePassenger(int counter) {
        if (q.empty()) {
            cout << "No passengers to serve.\n";
            return;
        }
        Passenger p = q.front();
        q.pop();
        served.push(p);

        cout << "\n--- Passenger Served at Counter " << counter << " ---\n";
        displayPassenger(p);
    }

    void displayPassenger(const Passenger &p) {
        cout << left << setw(12) << "TicketID"
             << setw(20) << "Name"
             << setw(6) << "Age"
             << setw(15) << "Destination"
             << setw(10) << "Class"
             << setw(25) << "Check-in Time" << "\n";

        cout << left << setw(12) << p.ticketID
             << setw(20) << p.name
             << setw(6) << p.age
             << setw(15) << p.destination
             << setw(10) << p.travelClass
             << setw(25) << p.timestamp << "\n";
    }

    void displayAll() {
        if (q.empty()) {
            cout << "No passengers waiting.\n";
            return;
        }

        cout << "\n---------- Waiting Passengers ----------\n";
        queue<Passenger> temp = q;
        while (!temp.empty()) {
            displayPassenger(temp.front());
            temp.pop();
        }
    }

    void displayServed() {
        if (served.empty()) {
            cout << "No served passenger records.\n";
            return;
        }

        cout << "\n---------- Served Passengers ----------\n";
        queue<Passenger> temp = served;
        while (!temp.empty()) {
            displayPassenger(temp.front());
            temp.pop();
        }
    }

    void searchTicket() {
        if (q.empty() && served.empty()) {
            cout << "No records available.\n";
            return;
        }

        int id;
        cout << "Enter Ticket ID: ";
        cin >> id;

        queue<Passenger> temp;

        temp = q;
        while (!temp.empty()) {
            if (temp.front().ticketID == id) {
                cout << "Passenger Found (Waiting)\n";
                displayPassenger(temp.front());
                return;
            }
            temp.pop();
        }

        temp = served;
        while (!temp.empty()) {
            if (temp.front().ticketID == id) {
                cout << "Passenger Found (Served)\n";
                displayPassenger(temp.front());
                return;
            }
            temp.pop();
        }

        cout << "No passenger found with Ticket ID " << id << ".\n";
    }

    void queueStatus() {
        cout << "Total Waiting Passengers: " << q.size() << "\n";
        cout << "Total Served Passengers: " << served.size() << "\n";
        cout << "Queue is " << (q.empty() ? "Empty" : "Active") << "\n";
    }
};

int main() {
    TicketQueue counter;
    int choice;

    do {
        cout << "\n========= ADVANCED TICKET COUNTER MENU =========\n";
        cout << "1. Insert New Passenger\n";
        cout << "2. Display Passenger at Front\n";
        cout << "3. Serve Passenger at Counter 1\n";
        cout << "4. Serve Passenger at Counter 2\n";
        cout << "5. Display Waiting Passengers\n";
        cout << "6. Display Served Passengers History\n";
        cout << "7. Search Passenger by Ticket ID\n";
        cout << "8. Queue Status\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: counter.insertPassenger(); break;
            case 2: counter.displayFront(); break;
            case 3: counter.servePassenger(1); break;
            case 4: counter.servePassenger(2); break;
            case 5: counter.displayAll(); break;
            case 6: counter.displayServed(); break;
            case 7: counter.searchTicket(); break;
            case 8: counter.queueStatus(); break;
            case 9: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 9);

    return 0;
}
