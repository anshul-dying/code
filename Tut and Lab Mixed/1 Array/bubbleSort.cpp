#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void inputArray(int arr[], int &size);
void displayArray(int arr[], int size);
void bubbleSort(int arr[], int size);
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
                bubbleSort(arr, size);
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

void inputArray(int arr[], int &size)
{
    cout << "Enter the size of the array (max " << MAX_SIZE << "): ";
    cin >> size;

    if (size > MAX_SIZE || size < 0)
    {
        cout << "Invalid size! Setting to maximum allowed size (" << MAX_SIZE << ").\n";
        size = MAX_SIZE;
    }

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }
    cout << "Array successfully created!\n";
}

void displayArray(int arr[], int size)
{
    if (size == 0)
    {
        cout << "Array is empty. Please input array first.\n";
        return;
    }

    cout << "Array elements:\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int size)
{
    bool swapped;

    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}
void displayMenu()
{
    cout << "1. Input Array\n";
    cout << "2. Display Array\n";
    cout << "3. Perform Bubble Sort\n";
    cout << "0. Exit\n";
}