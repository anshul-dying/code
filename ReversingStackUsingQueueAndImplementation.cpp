#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear;
    int *arr;
    int size;
public:
    CircularQueue(int size = 5) {
        front = rear = 0;
        this->size = size;
        arr = new int[size];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        front = (front + 1) % size;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return -1;
        }
        return arr[(front + 1) % size];
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        for (int i = (front + 1) % size; i != rear; i = (i + 1) % size) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << "\n";
    }
};

class Stack {
    int *arr;
    int top;
public:
    int capacity;
    Stack(int size = 100) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return -1;
        }
        return arr[top];
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

void reverseStack(Stack &st) {
    CircularQueue q(st.capacity);
    while (!st.isEmpty()) {
        q.enqueue(st.peek());
        st.pop();
    }
    while (!q.isEmpty()) {
        st.push(q.peek());
        q.dequeue();
    }
}

int main() {
    CircularQueue q(5);
    Stack st;
    int choice;
    do {
        cout << "\nMenu\n";
        cout << "1. Insert into Circular Queue\n";
        cout << "2. Remove from Queue\n";
        cout << "3. Reverse Stack\n";
        cout << "4. Print Circular Queue\n";
        cout << "5. Push into Stack\n";
        cout << "6. Pop from Stack\n";
        cout << "7. Print Stack\n";
        cout << "8. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int ele;
            cout << "Enter Element: ";
            cin >> ele;
            q.enqueue(ele);
            break;
        }
        case 2:
            q.dequeue();
            break;
        case 3:
            reverseStack(st);
            cout << "Reversed Stack: ";
            st.print();
            break;
        case 4:
            q.print();
            break;
        case 5: {
            int ele;
            cout << "Enter Element: ";
            cin >> ele;
            st.push(ele);
            break;
        }
        case 6:
            st.pop();
            break;
        case 7:
            st.print();
            break;
        case 8:
            cout << "Exiting\n";
            break;
        default:
            cout << "Invalid Command\n";
            break;
        }
    } while (choice != 8);

    return 0;
}