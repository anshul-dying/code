#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Stack class
class Stack
{
private:
    int top;
    int arr[MAX_SIZE];

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_SIZE - 1; }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements:\n";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << endl;
    }

    // Helper function to transfer stack to array (used before reversing)
    void toArray(int *tempArr, int &size)
    {
        size = 0;
        while (!isEmpty())
        {
            tempArr[size++] = pop();
        }
    }

    // Helper function to refill stack from array
    void fromArray(int *tempArr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            push(tempArr[i]);
        }
    }
};

// Queue class
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

    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear + 1) % MAX_SIZE == front; }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = val;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
        return val;
    }

    int getSize()
    {
        if (isEmpty())
            return 0;
        if (rear >= front)
            return rear - front + 1;
        else
            return MAX_SIZE - front + rear + 1;
    }
};

// Function to reverse stack using queue
void reverseStackUsingQueue(Stack &s)
{
    Queue q;
    int tempArr[MAX_SIZE];
    int size = 0;

    // Step 1: Pop all elements from stack and store in temp array
    s.toArray(tempArr, size);

    // Step 2: Enqueue all elements to queue
    for (int i = 0; i < size; i++)
    {
        q.enqueue(tempArr[i]);
    }

    // Step 3: Dequeue and push back to stack (this reverses the order)
    for (int i = 0; i < size; i++)
    {
        s.push(q.dequeue());
    }

    cout << "Stack reversed successfully!\n";
}

// Menu display
void displayMenu()
{
    cout << "1. Push into Stack\n";
    cout << "2. Display Stack\n";
    cout << "3. Reverse Stack Using Queue\n";
    cout << "0. Exit\n";
}

int main()
{
    Stack s;
    int choice, value;

    while (true)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.display();
            break;
        case 3:
            reverseStackUsingQueue(s);
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