#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;         // You can change this as needed
const int MAX_DISPLACEMENTS = 500; // Max kicks before giving up

class CuckooHash
{
private:
    vector<int> table1;
    vector<int> table2;
    vector<bool> occupied1;
    vector<bool> occupied2;

public:
    CuckooHash()
    {
        table1 = vector<int>(TABLE_SIZE, -1);
        table2 = vector<int>(TABLE_SIZE, -1);
        occupied1 = vector<bool>(TABLE_SIZE, false);
        occupied2 = vector<bool>(TABLE_SIZE, false);
    }

    int hash1(int key) { return key % TABLE_SIZE; }
    int hash2(int key) { return (key / TABLE_SIZE) % TABLE_SIZE; }

    bool insert(int key);
    bool search(int key);
    void display();
};

// Insert key using cuckoo hashing
bool CuckooHash::insert(int key)
{
    if (search(key))
    {
        cout << "Key " << key << " already exists.\n";
        return false;
    }

    int i = hash1(key);
    int j = hash2(key);

    // Try inserting into table1
    if (!occupied1[i])
    {
        table1[i] = key;
        occupied1[i] = true;
        cout << "Inserted " << key << " at Table1[" << i << "]\n";
        return true;
    }
    else if (!occupied2[j])
    {
        table2[j] = key;
        occupied2[j] = true;
        cout << "Inserted " << key << " at Table2[" << j << "]\n";
        return true;
    }

    // Displacement loop
    cout << "Inserting with displacement...\n";
    int currentKey = key;
    int pos = hash1(currentKey); // Start from table1
    int step = 0;

    while (step < MAX_DISPLACEMENTS)
    {
        // Alternate between table1 and table2
        if (step % 2 == 0)
        {
            pos = hash1(currentKey);
            if (!occupied1[pos])
            {
                table1[pos] = currentKey;
                occupied1[pos] = true;
                cout << "Inserted " << currentKey << " at Table1[" << pos << "]\n";
                return true;
            }
            else
            {
                // Swap with existing key
                int temp = table1[pos];
                table1[pos] = currentKey;
                currentKey = temp;
                cout << "Kicked out " << currentKey << " from Table1[" << pos << "]\n";
            }
        }
        else
        {
            pos = hash2(currentKey);
            if (!occupied2[pos])
            {
                table2[pos] = currentKey;
                occupied2[pos] = true;
                cout << "Inserted " << currentKey << " at Table2[" << pos << "]\n";
                return true;
            }
            else
            {
                int temp = table2[pos];
                table2[pos] = currentKey;
                currentKey = temp;
                cout << "Kicked out " << currentKey << " from Table2[" << pos << "]\n";
            }
        }
        step++;
    }

    cout << "Failed to insert key " << key << " after " << MAX_DISPLACEMENTS << " displacements.\n";
    return false;
}

// Search for a key
bool CuckooHash::search(int key)
{
    int i = hash1(key);
    int j = hash2(key);

    if ((occupied1[i] && table1[i] == key) || (occupied2[j] && table2[j] == key))
        return true;

    return false;
}

// Display both tables
void CuckooHash::display()
{
    cout << "\n=== Cuckoo Hash Tables ===\n";
    cout << "Table1 (hash1): ";
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (occupied1[i])
            cout << "[" << i << "]:" << table1[i] << " ";
        else
            cout << "[" << i << "]:- ";
    }
    cout << "\nTable2 (hash2): ";
    for (int j = 0; j < TABLE_SIZE; j++)
    {
        if (occupied2[j])
            cout << "[" << j << "]:" << table2[j] << " ";
        else
            cout << "[" << j << "]:- ";
    }
    cout << endl;
}

// Menu display
void displayMenu()
{
    cout << "1. Insert Key\n";
    cout << "2. Search Key\n";
    cout << "3. Display Tables\n";
    cout << "0. Exit\n";
}

int main()
{
    CuckooHash ch;
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
            ch.insert(key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (ch.search(key))
                cout << "Key " << key << " found.\n";
            else
                cout << "Key " << key << " not found.\n";
            break;
        case 3:
            ch.display();
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