#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int id;
    string name;
    string branch;
    double cgpa;
    string company;

    Student(int i, string n, string b, double c, string comp)
    {
        id = i;
        name = n;
        branch = b;
        cgpa = c;
        company = comp;
    }
};

class HashTable
{
    vector<list<Student>> table;
    int size;

public:
    HashTable(int s)
    {
        size = s;
        table.resize(size);
    }

    // simple hash function
    int hashFunction(int key)
    {
        return key % size;
    }

    // insert record
    void insertStudent(Student s)
    {
        int index = hashFunction(s.id);
        table[index].push_back(s);
        cout << "Record inserted successfully!\n";
    }

    // search
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
                cout << "Company: " << s.company << endl;
                return;
            }
        }
        cout << "Student not found!\n";
    }

    // delete
    void deleteStudent(int id)
    {
        int index = hashFunction(id);
        auto &chain = table[index];

        for (auto it = chain.begin(); it != chain.end(); ++it)
        {
            if (it->id == id)
            {
                chain.erase(it);
                cout << "Record deleted successfully!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }

    // display all
    void display()
    {
        cout << "\n------ All Placement Records ------\n";
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
                         << ", CGPA: " << s.cgpa
                         << ", Company: " << s.company << endl;
                }
            }
        }
    }
};

int main()
{
    HashTable ht(10);
    int choice;

    do
    {
        cout << "\n===== Smart College Placement Portal =====\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Search Student Record\n";
        cout << "3. Delete Student Record\n";
        cout << "4. Display All Records\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id;
            string name, branch, company;
            double cgpa;

            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Branch: ";
            cin >> branch;
            cout << "Enter CGPA: ";
            cin >> cgpa;
            cout << "Enter Company (or NA): ";
            cin >> company;

            ht.insertStudent(Student(id, name, branch, cgpa, company));
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
            ht.display();
        }
        else if (choice == 5)
        {
            cout << "Exiting...\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
