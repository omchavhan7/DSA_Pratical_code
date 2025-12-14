#include <iostream>
#include <string>
using namespace std;

class Faculty
{
public:
    int id;
    string name;
    string dept;

    Faculty()
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
    Faculty *table;

public:
    HashTable(int s)
    {
        size = s;
        table = new Faculty[size];
    }

    int hashFunction(int id)
    {
        return id % size;
    }

    void insert()
    {
        int id;
        string name, dept;

        cout << "Enter Faculty ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Faculty Name: ";
        getline(cin, name);

        cout << "Enter Department: ";
        getline(cin, dept);

        int index = hashFunction(id);
        int start = index;

        while (table[index].id != -1 && table[index].id != -2)
        {
            index = (index + 1) % size;
            if (index == start)
            {
                cout << "Hash Table Full! Cannot insert.\n";
                return;
            }
        }

        table[index].id = id;
        table[index].name = name;
        table[index].dept = dept;

        cout << "Record Inserted at index " << index << "\n";
    }

    void search()
    {
        int id;
        cout << "Enter Faculty ID to search: ";
        cin >> id;

        int index = hashFunction(id);
        int start = index;

        while (table[index].id != -1)
        {
            if (table[index].id == id)
            {
                cout << "\nFaculty Found:\n";
                cout << "ID   : " << table[index].id << "\n";
                cout << "Name : " << table[index].name << "\n";
                cout << "Dept : " << table[index].dept << "\n";
                return;
            }

            index = (index + 1) % size;
            if (index == start)
                break;
        }

        cout << "Faculty NOT Found!\n";
    }

    void deleteRecord()
    {
        int id;
        cout << "Enter Faculty ID to delete: ";
        cin >> id;

        int index = hashFunction(id);
        int start = index;

        while (table[index].id != -1)
        {
            if (table[index].id == id)
            {
                table[index].id = -2; // deleted marker
                table[index].name = "-";
                table[index].dept = "-";
                cout << "Faculty record deleted.\n";
                return;
            }

            index = (index + 1) % size;
            if (index == start)
                break;
        }

        cout << "Faculty NOT Found!\n";
    }

    void display()
    {
        cout << "\n====== FACULTY HASH TABLE ======\n";
        for (int i = 0; i < size; i++)
        {
            cout << i << " : ";
            if (table[i].id == -1)
                cout << "EMPTY\n";
            else if (table[i].id == -2)
                cout << "DELETED\n";
            else
                cout << "[" << table[i].id << ", "
                     << table[i].name << ", "
                     << table[i].dept << "]\n";
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
        cout << "\n========= FACULTY DATABASE MENU =========\n";
        cout << "1. Insert Faculty\n";
        cout << "2. Search Faculty\n";
        cout << "3. Delete Faculty\n";
        cout << "4. Display Database\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            ht.insert();
            break;
        case 2:
            ht.search();
            break;
        case 3:
            ht.deleteRecord();
            break;
        case 4:
            ht.display();
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
