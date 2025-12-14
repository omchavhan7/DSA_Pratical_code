#include <iostream>
using namespace std;

struct Student {
    string name;
    float marks;
    int newRoll;
};

void display(Student s[], int n) {
    cout << "\nName\tMarks\tNew Roll\n";
    for (int i = 0; i < n; i++)
        cout << s[i].name << "\t" << s[i].marks << "\t" << s[i].newRoll << endl;
}

void printMarks(Student s[], int n) {
    for (int i = 0; i < n; i++)
        cout << s[i].marks << " ";
    cout << endl;
}

void bubbleSort(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].marks < s[j + 1].marks) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
        cout << "After Pass " << i + 1 << ": ";
        printMarks(s, n);
    }
    for (int i = 0; i < n; i++)
        s[i].newRoll = i + 1;
}

int main() {
    int n, choice;
    Student s[100];
    bool entered = false;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Enter Student Marks\n";
        cout << "2. Display Students\n";
        cout << "3. Bubble Sort and Assign Roll Nos\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter number of students: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "\nStudent " << i + 1 << " Name: ";
                cin >> s[i].name;
                cout << "Enter Marks: ";
                cin >> s[i].marks;
                s[i].newRoll = 0;
            }
            entered = true;
            break;

        case 2:
            if (entered)
                display(s, n);
            else
                cout << "Enter data first.\n";
            break;

        case 3:
            if (entered) {
                cout << "\nPass-by-pass Bubble Sort:\n";
                bubbleSort(s, n);
                cout << "\nFinal Result (Topper gets Roll 1):\n";
                display(s, n);
            } else
                cout << "Enter data first.\n";
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
