#include <iostream>
using namespace std;

const int MAX_SIZE = 10; // Maximum size of the stack

// Stack class
class Stack
{
private:
    int top;
    int arr[MAX_SIZE];

public:
    // Constructor
    Stack()
    {
        top = -1;
    }

    // Stack operations as member functions
    bool isFull();
    bool isEmpty();
    void push(int value);
    void pop();
    int peek();
    void display();
};

// Check if stack is full
bool Stack::isFull()
{
    return (top == MAX_SIZE - 1);
}

// Check if stack is empty
bool Stack::isEmpty()
{
    return (top == -1);
}

// Push element onto stack
void Stack::push(int value)
{
    if (isFull())
    {
        cout << "Stack Overflow! Cannot push " << value << ". Stack is full.\n";
        return;
    }
    arr[++top] = value;
    cout << "Pushed: " << value << endl;
}

// Pop element from stack
void Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow! Cannot pop. Stack is empty.\n";
        return;
    }
    cout << "Popped: " << arr[top--] << endl;
}

// Peek at top element
int Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty.\n";
        return -1;
    }
    return arr[top];
}

// Display stack elements
void Stack::display()
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

// Function to display menu
void displayMenu()
{
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Display Stack\n";
    cout << "5. Check if Stack is Empty\n";
    cout << "6. Check if Stack is Full\n";
    cout << "0. Exit\n";
}

int main()
{
    Stack s;
    int choice, value;

    do
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
            s.pop();
            break;
        case 3:
            value = s.peek();
            if (value != -1)
                cout << "Top element is: " << value << endl;
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 6:
            cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl;
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