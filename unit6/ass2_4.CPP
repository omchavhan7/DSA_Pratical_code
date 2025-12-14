#include <bits/stdc++.h>
using namespace std;

// Structure to store student details
struct Student
{
    int id;
    string name;
    string branch;
    double cgpa;

    Student(int i, string n, string b, double c)
    {
        id = i;
        name = n;
        branch = b;
        cgpa = c;
    }
};

// Hash Table class
class HashTable
{
    vector<list<Student>> table; // chaining
    int size;

public:
    HashTable(int s)
    {
        size = s;
        table.resize(size);
    }

    // Simple hash function
    int hashFunction(int key)
    {
        return key % size;
    }

    // INSERT
    void insertStudent(Student s)
    {
        int index = hashFunction(s.id);
        table[index].push_back(s);
        cout << "Student record inserted successfully!\n";
    }

    // SEARCH
    void searchStudent(int id)
    {
        int index = hashFunction(id);
        for (auto &s : table[index])
        {
            if (s.id == id)
            {
                cout << "\n--- Student Found ---\n";
                cout << "ID: " << s.id << endl;
                cout << "Name: " << s.name << endl;
                cout << "Branch: " << s.branch << endl;
                cout << "CGPA: " << s.cgpa << endl;
                return;
            }
        }
        cout << "Student not found!\n";
    }

    // DELETE
    void deleteStudent(int id)
    {
        int index = hashFunction(id);
        auto &chain = table[index];

        for (auto it = chain.begin(); it != chain.end(); ++it)
        {
            if (it->id == id)
            {
                chain.erase(it);
                cout << "Student record deleted!\n";
                return;
            }
        }

        cout << "Student not found!\n";
    }

    // DISPLAY ALL STUDENTS
    void displayAll()
    {
        cout << "\n---- Student Database ----\n";
        for (int i = 0; i < size; i++)
        {
            if (!table[i].empty())
            {
                cout << "Bucket " << i << ":\n";
                for (auto &s : table[i])
                {
                    cout << "  ID: " << s.id
                         << ", Name: " << s.name
                         << ", Branch: " << s.branch
                         << ", CGPA: " << s.cgpa << endl;
                }
            }
        }
    }
};

int main()
{
    HashTable ht(10); // hash table of size 10
    int choice;

    do
    {
        cout << "\n===== Student Database Using Hashing =====\n";
        cout << "1. Insert Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id;
            string name, branch;
            double cgpa;

            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Branch: ";
            cin >> branch;
            cout << "Enter CGPA: ";
            cin >> cgpa;

            ht.insertStudent(Student(id, name, branch, cgpa));
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            ht.searchStudent(id);
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            ht.deleteStudent(id);
        }
        else if (choice == 4)
        {
            ht.displayAll();
        }
        else if (choice == 5)
        {
            cout << "Exiting...\n";
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
