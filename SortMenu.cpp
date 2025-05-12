#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int minIdx = i;
        for(int j = i; j < n; j++)
        {
            if(arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i) 
        {
            swap(arr[i], arr[minIdx]);
        }
    }
}

void merge(int* arr, int s, int e)
{
    int mid = s+(e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;


    int* left = new int[len1];
    int* right = new int[len2];

    //copy elements from arr to left and right
    int arrayIdx = s;
    for(int i = 0; i < len1; i++) 
    {
        left[i] = arr[arrayIdx];
        arrayIdx++;
    }
    arrayIdx = mid+1;
    for(int i = 0; i < len2; i++)
    {
        right[i] = arr[arrayIdx];
        arrayIdx++;
    }

    //merging left and right
    int leftIdx = 0;
    int rightIdx = 0;
    int mainArrIdx = s;
    while(leftIdx < len1 && rightIdx < len2)
    {
        if(left[leftIdx] < right[rightIdx])
        {
            arr[mainArrIdx] = left[leftIdx];
            mainArrIdx++;
            leftIdx++;
        }
        else
        {
            arr[mainArrIdx] = right[rightIdx];
            mainArrIdx++;
            rightIdx++;
        }
    }

    while(leftIdx < len1)
    {
        arr[mainArrIdx] = left[leftIdx];
        mainArrIdx++;
        leftIdx++;
    }

    while(rightIdx < len2)
    {
        arr[mainArrIdx] = right[rightIdx];
        mainArrIdx++;
        rightIdx++;
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int s, int e)
{
    if(s >= e) return;
    
    int mid = s+(e-s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge(arr, s, e);
}

bool binarySearch(int arr[], int n, int size)
{
    int s = 0;
    int e = size-1;
    int mid = s+(e-s)/2;

    while(s<=e)
    {
        if(arr[mid] == n)
        {
            return true;
        }
        else if(arr[mid] > n)
        {
            e = mid-1;
        }
        else s = mid+1;

        mid = s+(e-s)/2;
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int* arr = new int[n];
    int option = 0;

    while (true) {
        cout << "Enter option\n"
         << "1) Input array\n"
         << "2) Insertion Sort\n"
         << "3) Merge Sort\n"
         << "4) Selection Sort\n"
         << "5) Binary Search\n"
         << "6) Exit\n";
        cin >> option;
        if (option == 1) {
            cout << "Enter array elements for array size " << n << endl;
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
        } else if (option == 2) {
            cout << "Performing Insertion Sort\n";
            insertionSort(arr, n);
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        } else if (option == 3) {
            cout << "Performing Merge Sort\n";
            mergeSort(arr, 0, n-1);
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }else if (option == 4) {
            cout << "Performing Selection Sort\n";
            selectionSort(arr, n);
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if(option == 5)
        {
            mergeSort(arr, 0, n-1);
            int ele;
            cout << "Enter element to search: ";
            cin >> ele;
            if(binarySearch(arr, ele, n)) cout << "Found\n";
            else cout << "Not Found\n";
        } 
        else if (option == 6) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid option!\n";
        }
    }

    delete[] arr;
    return 0;
}
