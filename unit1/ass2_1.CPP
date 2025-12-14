#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string year;
    string div;
    string name;
    int roll;
};

int main()
{
    int n, choice;
    Student s[100];

    cout << "Enter total number of students present on ground: ";
    cin >> n;
    cin.ignore();

    cout << "\nEnter details of all students:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << ":\n";

        cout << "Enter Year (SY/TY/BTech): ";
        getline(cin, s[i].year);

        cout << "Enter Division: ";
        getline(cin, s[i].div);

        cout << "Enter Name: ";
        getline(cin, s[i].name);

        cout << "Enter Roll Number: ";
        cin >> s[i].roll;
        cin.ignore();
    }

    do
    {
        cout << "\n================= MENU =================\n";
        cout << "1. Display All Students\n";
        cout << "2. Search for Student (SY, Div X, Name XYZ, Roll 17)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {

        case 1:
        {
            cout << "\nList of Students on Ground:\n";
            cout << "----------------------------------------\n";
            for (int i = 0; i < n; i++)
            {
                cout << "Year: " << s[i].year
                     << ", Div: " << s[i].div
                     << ", Name: " << s[i].name
                     << ", Roll: " << s[i].roll << endl;
            }
            break;
        }

        case 2:
        {
            bool found = false;

            for (int i = 0; i < n; i++)
            {
                if (s[i].year == "SY" &&
                    s[i].div == "X" &&
                    s[i].name == "XYZ" &&
                    s[i].roll == 17)
                {
                    found = true;
                    cout << "\nStudent FOUND!\n";
                    cout << "Year: " << s[i].year << endl;
                    cout << "Division: " << s[i].div << endl;
                    cout << "Name: " << s[i].name << endl;
                    cout << "Roll: " << s[i].roll << endl;
                    break;
                }
            }

            if (!found)
                cout << "\nStudent NOT FOUND.\n";

            break;
        }

        case 3:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
