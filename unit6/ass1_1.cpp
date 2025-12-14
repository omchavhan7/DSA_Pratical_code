#include <iostream>
using namespace std;

class HashTable
{
private:
    int *table;
    int size;

public:
    HashTable(int s)
    {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1; // -1 = empty slot
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != -1)
        {
            index = (index + 1) % size;

            if (index == start)
            {
                cout << "Hash Table is full! Cannot insert.\n";
                return;
            }
        }

        table[index] = key;
        cout << "Inserted " << key << " at index " << index << "\n";
    }

    void searchKey(int key)
    {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                cout << key << " found at index " << index << "\n";
                return;
            }
            index = (index + 1) % size;

            if (index == start)
                break;
        }

        cout << key << " not found.\n";
    }

    void deleteKey(int key)
    {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                table[index] = -2; // -2 = deleted marker
                cout << key << " deleted from index " << index << "\n";
                return;
            }
            index = (index + 1) % size;

            if (index == start)
                break;
        }

        cout << key << " not found.\n";
    }

    void display()
    {
        cout << "\nHash Table Contents:\n";
        for (int i = 0; i < size; i++)
        {
            if (table[i] == -1)
                cout << i << " : EMPTY\n";
            else if (table[i] == -2)
                cout << i << " : DELETED\n";
            else
                cout << i << " : " << table[i] << "\n";
        }
    }
};

int main()
{
    int size, choice, key;

    cout << "Enter size of hash table: ";
    cin >> size;

    HashTable ht(size);

    do
    {
        cout << "\n======= HASH TABLE MENU =======\n";
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
