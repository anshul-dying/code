#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the array

// Function prototypes
void displayMenu();
void inputArray(int arr[], int &size);
void displayArray(const int arr[], int size);
void insertionSort(int arr[], int size);

int main()
{
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            inputArray(arr, size);
            break;
        case 2:
            if (size == 0)
                cout << "Error: Array is empty. Please input elements first.\n";
            else
                displayArray(arr, size);
            break;
        case 3:
            if (size == 0)
                cout << "Error: Array is empty. Please input elements first.\n";
            else
            {
                insertionSort(arr, size);
                cout << "Array sorted using Insertion Sort!\n";
            }
            break;
        case 0:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

// Display menu options
void displayMenu()
{
    cout << "1. Input Array\n";
    cout << "2. Display Array\n";
    cout << "3. Perform Insertion Sort\n";
    cout << "0. Exit\n";
}

// Input array elements
void inputArray(int arr[], int &size)
{
    cout << "Enter the size of the array (max " << MAX_SIZE << "): ";
    cin >> size;

    if (size > MAX_SIZE || size < 0)
    {
        cout << "Invalid size entered. Setting to maximum allowed size (" << MAX_SIZE << ").\n";
        size = MAX_SIZE;
    }

    cout << "Enter " << size << " integer elements:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Array successfully created!\n";
}

// Display array elements
void displayArray(const int arr[], int size)
{
    cout << "Current array elements:\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Insertion Sort algorithm
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}