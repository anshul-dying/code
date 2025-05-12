#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack {
    int top;
    int size;
    T* arr;
public:
    Stack(int size) {
        this->size = size;
        arr = new T[size];
        this->top = -1;
    }

    void push(T value) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    T pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            throw runtime_error("Stack Underflow");
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    T peek() {
        if (top == -1) {
            throw runtime_error("Stack is Empty");
        }
        return arr[top];
    }
};

string postfixToInfix(string postfix) {
    int n = postfix.length();
    Stack<string> st(n);

    for (int i = 0; i < n; i++) {
        char c = postfix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            string operand(1, c);
            st.push(operand);
        } else {
            string operand2 = st.pop();
            string operand1 = st.pop();
            string expr = "(" + operand1 + c + operand2 + ")";
            st.push(expr);
        }
    }

    return st.pop();
}

int main() {
    string postfix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    try {
        string infix = postfixToInfix(postfix);
        cout << "Infix Expression: " << infix << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
