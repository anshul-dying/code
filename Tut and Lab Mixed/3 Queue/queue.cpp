#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Fixed size of the queue

class Queue
{
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return rear == MAX_SIZE - 1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow! Cannot insert " << value << ".\n";
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        arr[++rear] = value;
        cout << "Inserted: " << value << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! Queue is empty.\n";
            return;
        }
        cout << "Deleted: " << arr[front] << endl;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements:\n";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void displayMenu()
{
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Display Queue\n";
    cout << "0. Exit\n";
}

int main()
{
    Queue q;
    int choice, value;

    while (true)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
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