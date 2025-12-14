#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee
{
public:
    int id;
    string name;
    string dept;

    Employee()
    {
        id = -1; // empty
        name = "-";
        dept = "-";
    }
};

class HashTable
{
private:
    int size;
    Employee *table;

public:
    HashTable(int s)
    {
        size = s;
        table = new Employee[size];
    }

    // Mid Square Hashing
    int midSquareHash(int key)
    {
        long long sq = (long long)key * key; // square

        string s = to_string(sq);

        int len = s.length();
        int mid = len / 2;

        // take 2 middle digits
        string middle;

        if (len >= 2)
            middle = s.substr(mid - 1, 2);
        else
            middle = s;

        int hashValue = stoi(middle);

        return hashValue % size;
    }

    void insertEmployee()
    {
        int id;
        string name, dept;

        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Employee Department: ";
        getline(cin, dept);

        int index = midSquareHash(id);

        // Linear probing if collision
        int start = index;
        while (table[index].id != -1)
        {
            index = (index + 1) % size;
            if (index == start)
            {
                cout << "Hash Table Full! Cannot Insert.\n";
                return;
            }
        }

        table[index].id = id;
        table[index].name = name;
        table[index].dept = dept;

        cout << "Inserted at index " << index << "\n";
    }

    void searchEmployee()
    {
        int id;
        cout << "Enter Employee ID to search: ";
        cin >> id;

        int index = midSquareHash(id);
        int start = index;

        while (table[index].id != -1)
        {
            if (table[index].id == id)
            {
                cout << "\nEmployee Found!\n";
                cout << "ID   : " << table[index].id << "\n";
                cout << "Name : " << table[index].name << "\n";
                cout << "Dept : " << table[index].dept << "\n";
                return;
            }
            index = (index + 1) % size;

            if (index == start)
                break;
        }

        cout << "Employee not found.\n";
    }

    void display()
    {
        cout << "\n===== EMPLOYEE HASH TABLE =====\n";
        cout << "Index | ID | Name | Dept\n";
        cout << "-----------------------------\n";

        for (int i = 0; i < size; i++)
        {
            cout << setw(5) << i << " | ";
            if (table[i].id == -1)
                cout << "EMPTY\n";
            else
                cout << table[i].id << " , "
                     << table[i].name << " , "
                     << table[i].dept << "\n";
        }
    }
};

int main()
{
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;

    HashTable ht(size);

    int choice;
    do
    {
        cout << "\n========= EMPLOYEE DATABASE MENU =========\n";
        cout << "1. Insert Employee\n";
        cout << "2. Search Employee\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            ht.insertEmployee();
            break;
        case 2:
            ht.searchEmployee();
            break;
        case 3:
            ht.display();
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
