#include <iostream>
#include <cstring>
using namespace std;

class Stack {
    int* arr;
    int top;
    int size;

public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int value) {
        if (top == size - 1) return;
        arr[++top] = value;
    }

    int pop() {
        if (top == -1) return -1;
        return arr[top--];
    }

    int peek() {
        if (top == -1) return -1;
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int evaluatePostfix(char* expr) {
    int n = strlen(expr);
    Stack st(n);

    for (int i = 0; i < n; i++) {
        char c = expr[i];

        if (c >= '0' && c <= '9') {
            st.push(c - '0');
        } else {
            int b = st.pop();
            int a = st.pop();

            if (c == '+')
                st.push(a + b);
            else if (c == '-')
                st.push(a - b);
            else if (c == '*')
                st.push(a * b);
            else if (c == '/')
                st.push(a / b);
            else if (c == '^') {
                int result = 1;
                for (int j = 0; j < b; j++)
                    result *= a;
                st.push(result);
            }
        }
    }

    return st.pop();
}

int main() {
    char expr[100];
    cout << "Enter postfix expression: ";
    cin >> expr;

    cout << "Result: " << evaluatePostfix(expr) << endl;
    return 0;
}
