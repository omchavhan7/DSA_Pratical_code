#include <iostream>
#include <list>
using namespace std;

class HashTable
{
private:
    int size;
    list<int> *table; // Array of linked lists

public:
    HashTable(int s)
    {
        size = s;
        table = new list<int>[size];
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << key << " inserted at index " << index << endl;
    }

    void searchKey(int key)
    {
        int index = hashFunction(key);

        for (int val : table[index])
        {
            if (val == key)
            {
                cout << key << " found at index " << index << endl;
                return;
            }
        }
        cout << key << " not found!" << endl;
    }

    void deleteKey(int key)
    {
        int index = hashFunction(key);

        for (auto it = table[index].begin(); it != table[index].end(); it++)
        {
            if (*it == key)
            {
                table[index].erase(it);
                cout << key << " deleted from index " << index << endl;
                return;
            }
        }

        cout << key << " not found!" << endl;
    }

    void display()
    {
        cout << "\nHash Table (Separate Chaining):\n";
        for (int i = 0; i < size; i++)
        {
            cout << i << " --> ";
            for (int val : table[i])
            {
                cout << val << " -> ";
            }
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
        cout << "\n===== HASH TABLE MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            ht.searchKey(key);
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
