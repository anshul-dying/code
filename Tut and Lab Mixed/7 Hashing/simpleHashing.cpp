#include <iostream>
using namespace std;

const int TABLE_SIZE = 11;  // Rows for mod 11
const int COL_CAPACITY = 2; // 2 slots per bucket

class HashTable
{
private:
    int table[TABLE_SIZE][COL_CAPACITY];

public:
    HashTable()
    {
        // Initialize all slots to -1 (empty)
        for (int i = 0; i < TABLE_SIZE; i++)
            for (int j = 0; j < COL_CAPACITY; j++)
                table[i][j] = -1;
    }

    void insert(int key);
    bool search(int key);
    void display();
};

// Hash function
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

// Insert key into hash table
void HashTable::insert(int key)
{
    int index = hashFunction(key);

    for (int col = 0; col < COL_CAPACITY; col++)
    {
        if (table[index][col] == -1 || table[index][col] == key)
        {
            table[index][col] = key;
            cout << "Inserted " << key << " at position [" << index << "][" << col << "]\n";
            return;
        }
    }

    cout << "Overflow at index " << index << ". Cannot insert " << key << ".\n";
}

// Search for a key in hash table
bool HashTable::search(int key)
{
    int index = hashFunction(key);

    for (int col = 0; col < COL_CAPACITY; col++)
    {
        if (table[index][col] == key)
            return true;
    }

    return false;
}

// Display hash table contents
void HashTable::display()
{
    cout << "\nHash Table (11x2):\n";
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << "[" << i << "] -> ";
        for (int j = 0; j < COL_CAPACITY; j++)
        {
            if (table[i][j] != -1)
                cout << table[i][j] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }
}

// Display menu options
void displayMenu()
{
    cout << "1. Insert Key\n";
    cout << "2. Search Key\n";
    cout << "3. Display Hash Table\n";
    cout << "0. Exit\n";
}

int main()
{
    HashTable ht;
    int choice, key;

    while (true)
    {
        displayMenu();
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
            if (ht.search(key))
                cout << "Key " << key << " found in the hash table.\n";
            else
                cout << "Key " << key << " not found.\n";
            break;
        case 3:
            ht.display();
            break;
        case 0:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}