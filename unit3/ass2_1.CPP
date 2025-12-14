#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string problem;

    Patient(int i, string n, int a, string p) {
        id = i;
        name = n;
        age = a;
        problem = p;
    }
};

class Clinic {
private:
    queue<Patient> q;
    int nextID = 1;

public:
    void checkIn() {
        string name, problem;
        int age;

        cout << "Enter patient name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter problem: ";
        cin >> problem;

        Patient newPatient(nextID++, name, age, problem);
        q.push(newPatient);

        cout << "Patient Checked In. Assigned ID: " << newPatient.id << "\n";
    }

    void assignDoctor() {
        if (q.empty()) {
            cout << "No patients waiting.\n";
            return;
        }
        Patient p = q.front();
        q.pop();

        cout << "\n----- Patient Assigned to Doctor -----\n";
        cout << "ID: " << p.id << "\n";
        cout << "Name: " << p.name << "\n";
        cout << "Age: " << p.age << "\n";
        cout << "Problem: " << p.problem << "\n";
    }

    void showWaitingList() {
        if (q.empty()) {
            cout << "No patients in queue.\n";
            return;
        }

        cout << "\n----- Waiting Patients -----\n";
        queue<Patient> temp = q;
        while (!temp.empty()) {
            Patient p = temp.front();
            cout << "ID: " << p.id << " | Name: " << p.name 
                 << " | Age: " << p.age 
                 << " | Problem: " << p.problem << "\n";
            temp.pop();
        }
    }

    void countPatients() {
        cout << "Total Patients in Queue: " << q.size() << "\n";
    }

    void peekNextPatient() {
        if (q.empty()) {
            cout << "No patients waiting.\n";
            return;
        }
        Patient p = q.front();
        cout << "\n----- Next Patient in Queue -----\n";
        cout << "ID: " << p.id << "\n";
        cout << "Name: " << p.name << "\n";
        cout << "Age: " << p.age << "\n";
        cout << "Problem: " << p.problem << "\n";
    }
};

int main() {
    Clinic clinic;
    int choice;

    do {
        cout << "\n============== ADVANCED CLINIC MENU ==============\n";
        cout << "1. Check-in New Patient\n";
        cout << "2. Assign Next Patient to Doctor\n";
        cout << "3. Show Waiting List\n";
        cout << "4. Show Next Patient (Peek)\n";
        cout << "5. Total Patients in Queue\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: clinic.checkIn(); break;
            case 2: clinic.assignDoctor(); break;
            case 3: clinic.showWaitingList(); break;
            case 4: clinic.peekNextPatient(); break;
            case 5: clinic.countPatients(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n"; break;
        }

    } while(choice != 6);

    return 0;
}
