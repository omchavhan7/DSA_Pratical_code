#include <iostream>
#include <string>
using namespace std;

class Faculty {
public:
    int id;
    string name;
    string dept;
    int chain;      // pointer to next element in chain

    Faculty() {
        id = -1;            // empty
        name = "-";
        dept = "-";
        chain = -1;         // end of chain
    }
};

class HashTable {
private:
    int size;
    Faculty *table;

public:
    HashTable(int s) {
        size = s;
        table = new Faculty[size];
    }

    int hashFunction(int id) {
        return id % size;       // Divide method
    }

    void insertFaculty() {
        int id;
        string name, dept;

        cout << "Enter Faculty ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Department: ";
        getline(cin, dept);

        int index = hashFunction(id);

        // CASE 1: Slot empty → insert directly
        if (table[index].id == -1) {
            table[index].id = id;
            table[index].name = name;
            table[index].dept = dept;
            table[index].chain = -1;
            cout << "Faculty inserted at index " << index << endl;
            return;
        }

        // CASE 2: Collision → Linear probing to find free slot
        int newIndex = (index + 1) % size;

        while (table[newIndex].id != -1) {
            newIndex = (newIndex + 1) % size;
            if (newIndex == index) {
                cout << "Hash table full! Cannot insert.\n";
                return;
            }
        }

        // Insert at found slot
        table[newIndex].id = id;
        table[newIndex].name = name;
        table[newIndex].dept = dept;

        // Update chain of primary index
        int current = index;
        while (table[current].chain != -1)
            current = table[current].chain;

        table[current].chain = newIndex;

        cout << "Faculty inserted at index " << newIndex << endl;
    }

    void searchFaculty() {
        int id;
        cout << "Enter Faculty ID to search: ";
        cin >> id;

        int index = hashFunction(id);

        // If primary slot empty, not found
        if (table[index].id == -1) {
            cout << "Faculty NOT found.\n";
            return;
        }

        // Search through chain
        int current = index;

        while (current != -1) {
            if (table[current].id == id) {
                cout << "\nFaculty Found:\n";
                cout << "ID   : " << table[current].id << endl;
                cout << "Name : " << table[current].name << endl;
                cout << "Dept : " << table[current].dept << endl;
                return;
            }
            current = table[current].chain;
        }

        cout << "Faculty NOT found!\n";
    }

    void display() {
        cout << "\n======= FACULTY HASH TABLE =======\n";
        cout << "Index | ID | Name | Dept | Chain\n";
        cout << "------------------------------------\n";

        for (int i = 0; i < size; i++) {
            cout << i << " --> ";

            if (table[i].id == -1)
                cout << "EMPTY\n";
            else
                cout << table[i].id << " , " << table[i].name
                     << " , " << table[i].dept
                     << " , chain -> " << table[i].chain << "\n";
        }
    }
};

int main() {
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;

    HashTable ht(size);

    int choice;
    do {
        cout << "\n==== FACULTY DATABASE MENU ====\n";
        cout << "1. Insert Faculty\n";
        cout << "2. Search Faculty\n";
        cout << "3. Display Table\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: ht.insertFaculty(); break;
            case 2: ht.searchFaculty(); break;
            case 3: ht.display(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
