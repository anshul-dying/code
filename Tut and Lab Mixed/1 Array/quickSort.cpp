#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Function declarations
void inputArray(int arr[], int &size);
void displayArray(int arr[], int size);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void displayMenu();

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
            displayArray(arr, size);
            break;
        case 3:
            if (size == 0)
                cout << "Error: Array is empty. Please input array first.\n";
            else
            {
                quickSort(arr, 0, size - 1);
                cout << "Sorting complete!\n";
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

// Input array elements
void inputArray(int arr[], int &size)
{
    cout << "Enter the size of the array (max " << MAX_SIZE << "): ";
    cin >> size;

    if (size > MAX_SIZE || size < 1)
    {
        cout << "Invalid size entered. Setting to maximum allowed size (" << MAX_SIZE << ").\n";
        size = MAX_SIZE;
    }

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i)
    {
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }
    cout << "Array successfully created!\n";
}

// Display array elements
void displayArray(int arr[], int size)
{
    if (size == 0)
    {
        cout << "Error: Array is empty. Please input array first.\n";
        return;
    }

    cout << "Current array elements:\n";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Quick Sort Implementation
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);  // Left side
        quickSort(arr, pivotIndex + 1, high); // Right side
    }
}

// Partition function with last element as pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Pivot element
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in correct position
    return i + 1;
}

// Display menu
void displayMenu()
{
    cout << "1. Input Array\n";
    cout << "2. Display Array\n";
    cout << "3. Perform Quick Sort\n";
    cout << "0. Exit\n";
}