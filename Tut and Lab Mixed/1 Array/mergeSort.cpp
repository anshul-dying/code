#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Function declarations
void inputArray(int arr[], int &size);
void displayArray(int arr[], int size);
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
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
                mergeSort(arr, 0, size - 1);
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

// Merge Sort Implementation
void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

// Merge two sorted subarrays
void merge(int arr[], int low, int mid, int high)
{
    const int size = high - low + 1;
    int temp[size];

    int i = low, j = mid + 1, k = 0;

    // Merge two sorted parts into temp[]
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements from left half
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements from right half
    while (j <= high)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (int idx = 0; idx < size; ++idx)
        arr[low + idx] = temp[idx];
}

// Display menu
void displayMenu()
{
    cout << "1. Input Array\n";
    cout << "2. Display Array\n";
    cout << "3. Perform Merge Sort\n";
    cout << "0. Exit\n";
}