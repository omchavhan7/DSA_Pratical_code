#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class HashTable
{
private:
    int size;
    vector<list<int>> table; // Separate Chaining (linked lists)

public:
    HashTable(int s)
    {
        size = s;
        table.resize(size);
    }

    int hashFunction(int key)
    {
        return key % size; // MOD method
    }

    void insertKey(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << "Inserted " << key << " at index " << index << endl;
    }

    bool searchKey(int key)
    {
        int index = hashFunction(key);
        for (int val : table[index])
        {
            if (val == key)
                return true;
        }
        return false;
    }

    void deleteKey(int key)
    {
        int index = hashFunction(key);

        for (auto it = table[index].begin(); it != table[index].end(); it++)
        {
            if (*it == key)
            {
                table[index].erase(it);
                cout << "Deleted " << key << " from index " << index << endl;
                return;
            }
        }
        cout << "Key " << key << " not found!\n";
    }

    void display()
    {
        cout << "\n===== Hash Table (Separate Chaining) =====\n";
        for (int i = 0; i < size; i++)
        {
            cout << i << " --> ";
            for (int val : table[i])
                cout << val << " -> ";
            cout << "NULL\n";
        }
    }
};

int main()
{
    int size, choice, key;

    cout << "Enter size of Hash Table: ";
    cin >> size;

    HashTable ht(size);

    do
    {
        cout << "\n=========== MENU ===========\n";
        cout << "1. Insert Key\n";
        cout << "2. Search Key\n";
        cout << "3. Delete Key\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insertKey(key);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (ht.searchKey(key))
                cout << key << " found in table\n";
            else
                cout << key << " not found\n";
            break;

        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            ht.deleteKey(key);
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
