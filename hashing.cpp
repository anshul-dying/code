#include <iostream>
using namespace std;

#define HASHING 11

class HashTable
{
private:
    static const int ROWS = HASHING;
    static const int COLS = 2;
    int table[ROWS][COLS];

    int hashFunction(int key)
    {
        return key % ROWS;
    }

public:
    HashTable()
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                table[i][j] = -1;
            }
        }
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        int originalIndex = index;

        if (table[index][0] == -1)
        {
            table[index][0] = key;
            return;
        }
        else if (table[index][1] == -1)
        {
            table[index][1] = key;
            return;
        }

        while (table[index][0] != -1 && table[index][1] != -1)
        {
            index = (index + 1) % ROWS;

            if (index == originalIndex)
            {
                cout << "Hash table is full, cannot insert " << key << endl;
                return;
            }
        }

        if (table[index][0] == -1)
        {
            table[index][0] = key;
        }
        else
        {
            table[index][1] = key;
        }
    }

    void display()
    {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < ROWS; i++)
        {
            cout << i << "\t: ";
            if (table[i][0] != -1)
                cout << table[i][0];
            if (table[i][1] != -1)
                cout << "\t" << table[i][1];
            cout << endl;
        }
    }

    void insertArray(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            insert(arr[i]);
        }
    }
};

int main()
{
    HashTable ht;
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid size!" << endl;
        return 1;
    }

    int *arr = new int[size];

    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    ht.insertArray(arr, size);

    ht.display();

    delete[] arr;

    return 0;
}