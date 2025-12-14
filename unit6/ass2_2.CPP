#include <iostream>
#include <string>
using namespace std;

class Faculty
{
public:
    int id;
    string name;
    string dept;
    int chain;

    Faculty()
    {
        id = -1;    // empty
        chain = -1; // no chain link
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

    int hashFunc(int key)
    {
        return key % size; // Divide method
    }

    // Helper: find next empty slot
    int findEmpty(int index)
    {
        int start = index;
        while (table[index].id != -1)
        {
            index = (index + 1) % size;
            if (index == start)
                return -1;
        }
        return index;
    }

    // Insert using Chaining WITH Replacement
    void insertFaculty()
    {
        int id;
        string name, dept;

        cout << "Enter Faculty ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Department: ";
        getline(cin, dept);

        int index = hashFunc(id);

        // Case 1: Slot empty → insert directly
        if (table[index].id == -1)
        {
            table[index].id = id;
            table[index].name = name;
            table[index].dept = dept;
            table[index].chain = -1;
            cout << "Inserted at index " << index << "\n";
            return;
        }

        // Case 2: Slot occupied – Check if replacement needed
        int existingHash = hashFunc(table[index].id);

        if (existingHash != index)
        {
            // REPLACEMENT NEEDED
            cout << "\n*** REPLACEMENT OCCURRED ***\n";

            // Find empty slot for displaced record
            int emptySlot = findEmpty(index);
            if (emptySlot == -1)
            {
                cout << "Hash table full! Cannot insert.\n";
                return;
            }

            // Move displaced record
            table[emptySlot] = table[index];

            // Fix chain links pointing to old index
            int prev = existingHash;
            while (table[prev].chain != index)
                prev = table[prev].chain;

            table[prev].chain = emptySlot;

            // Insert new record at original index
            table[index].id = id;
            table[index].name = name;
            table[index].dept = dept;
            table[index].chain = -1;

            cout << "Inserted at index " << index << "\n";
            return;
        }

        // Case 3: Normal chaining (no replacement)
        int emptySlot = findEmpty(index);
        if (emptySlot == -1)
        {
            cout << "Hash table full!\n";
            return;
        }

        int temp = index;
        while (table[temp].chain != -1)
            temp = table[temp].chain;

        table[temp].chain = emptySlot;

        table[emptySlot].id = id;
        table[emptySlot].name = name;
        table[emptySlot].dept = dept;

        cout << "Inserted at index " << emptySlot << "\n";
    }

    // Search using chain traversal
    void searchFaculty()
    {
        int id;
        cout << "Enter Faculty ID to search: ";
        cin >> id;

        int index = hashFunc(id);

        if (table[index].id == -1)
        {
            cout << "Not found.\n";
            return;
        }

        int current = index;
        while (current != -1)
        {
            if (table[current].id == id)
            {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << table[current].id << "\n";
                cout << "Name: " << table[current].name << "\n";
                cout << "Dept: " << table[current].dept << "\n";
                return;
            }
            current = table[current].chain;
        }

        cout << "Faculty NOT found!\n";
    }

    void display()
    {
        cout << "\n===== HASH TABLE =====\n";
        cout << "Index | ID | Name | Dept | Chain\n";
        cout << "-----------------------------------\n";

        for (int i = 0; i < size; i++)
        {
            cout << i << " : ";
            if (table[i].id == -1)
                cout << "EMPTY\n";
            else
                cout << table[i].id << " , " << table[i].name
                     << " , " << table[i].dept
                     << " , " << table[i].chain << "\n";
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
        cout << "\n===== FACULTY HASH TABLE MENU =====\n";
        cout << "1. Insert Faculty\n";
        cout << "2. Search Faculty\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Select option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            ht.insertFaculty();
            break;
        case 2:
            ht.searchFaculty();
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
