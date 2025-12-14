#include <iostream>
using namespace std;

struct Student {
    string name;
    int roll_no;
    float total_marks;
};

void display(Student s[], int n) {
    cout << "\nName\tRoll No\tMarks\n";
    for (int i = 0; i < n; i++)
        cout << s[i].name << "\t" << s[i].roll_no << "\t" << s[i].total_marks << endl;
}

int bubbleSort(Student s[], int n) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (s[j].roll_no > s[j + 1].roll_no) {
                swap(s[j], s[j + 1]);
                swaps++;
            }
    return swaps;
}

int quickSwaps = 0;

int partition(Student s[], int low, int high) {
    int pivot = s[high].roll_no, i = low - 1;
    for (int j = low; j < high; j++)
        if (s[j].roll_no < pivot) {
            i++;
            swap(s[i], s[j]);
            quickSwaps++;
        }
    swap(s[i + 1], s[high]);
    quickSwaps++;
    return i + 1;
}

void quickSort(Student s[], int low, int high) {
    if (low < high) {
        int pi = partition(s, low, high);
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, high);
    }
}

int main() {
    int n, choice;
    Student A[100], B[100];
    bool dataEntered = false;

    do {
        cout << "\n---------- MENU ----------\n";
        cout << "1. Enter Student Data\n";
        cout << "2. Display Students\n";
        cout << "3. Bubble Sort (Roll No)\n";
        cout << "4. Quick Sort (Roll No)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter number of students: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "\nStudent " << i + 1 << ":\n";
                cout << "Name: ";
                cin >> A[i].name;
                cout << "Roll No: ";
                cin >> A[i].roll_no;
                cout << "Total Marks: ";
                cin >> A[i].total_marks;
                B[i] = A[i];
            }
            dataEntered = true;
            break;

        case 2:
            if (dataEntered) display(A, n);
            else cout << "Enter data first.\n";
            break;

        case 3:
            if (dataEntered) {
                int swaps = bubbleSort(A, n);
                cout << "\nAfter Bubble Sort:";
                display(A, n);
                cout << "Bubble Sort swaps = " << swaps << endl;
            } else cout << "Enter data first.\n";
            break;

        case 4:
            if (dataEntered) {
                for (int i = 0; i < n; i++) B[i] = A[i];
                quickSwaps = 0;
                quickSort(B, 0, n - 1);
                cout << "\nAfter Quick Sort:";
                display(B, n);
                cout << "Quick Sort swaps = " << quickSwaps << endl;
            } else cout << "Enter data first.\n";
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
