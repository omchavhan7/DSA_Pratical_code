#include <iostream>
#include <list>
#include <string>
using namespace std;

class Student
{
public:
    int roll;
    string name;
    float marks;

    Student(int r, string n, float m)
    {
        roll = r;
        name = n;
        marks = m;
    }
};

class HashTable
{
private:
    int size;
    list<Student> *table;

public:
    HashTable(int s)
    {
        size = s;
        table = new list<Student>[size];
    }

    int hashFunction(int roll)
    {
        return roll % size;
    }

    void insertStudent()
    {
        int roll;
        string name;
        float marks;

        cout << "Enter Roll Number: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;

        int index = hashFunction(roll);
        table[index].push_back(Student(roll, name, marks));

        cout << "Student record added successfully.\n";
    }

    void searchStudent()
    {
        int roll;
        cout << "Enter Roll Number to search: ";
        cin >> roll;

        int index = hashFunction(roll);

        for (auto &s : table[index])
        {
            if (s.roll == roll)
            {
                cout << "\nStudent Found:\n";
                cout << "Roll No: " << s.roll << endl;
                cout << "Name   : " << s.name << endl;
                cout << "Marks  : " << s.marks << endl;
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void deleteStudent()
    {
        int roll;
        cout << "Enter Roll Number to delete: ";
        cin >> roll;

        int index = hashFunction(roll);

        for (auto it = table[index].begin(); it != table[index].end(); it++)
        {
            if (it->roll == roll)
            {
                table[index].erase(it);
                cout << "Student deleted successfully.\n";
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void displayTable()
    {
        cout << "\n===== Student Hash Table =====\n";
        for (int i = 0; i < size; i++)
        {
            cout << i << " -> ";
            for (auto &s : table[i])
            {
                cout << "[" << s.roll << ", " << s.name << ", " << s.marks << "] -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main()
{
    int size;
    cout << "Enter size of Hash Table: ";
    cin >> size;

    HashTable ht(size);
    int choice;

    do
    {
        cout << "\n===== STUDENT RECORD MENU =====\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Search Student by Roll Number\n";
        cout << "3. Delete Student Record\n";
        cout << "4. Display All Records\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            ht.insertStudent();
            break;
        case 2:
            ht.searchStudent();
            break;
        case 3:
            ht.deleteStudent();
            break;
        case 4:
            ht.displayTable();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
