#include <iostream>
#include <cstring>
using namespace std;

class Stack {
    char* arr;
    int top;
    int size;

public:
    Stack(int size) {
        this->size = size;
        arr = new char[size];
        top = -1;
    }

    void push(char c) {
        if (top == size - 1) return;
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) return '\0';
        return arr[top--];
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '/' || c == '*') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void infixToPostfix(char* s) {
    int n = strlen(s);
    Stack st(n);
    char* result = new char[n + 1];
    int k = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result[k++] = c;

        else if (c == '(')
            st.push(c);

        else if (c == ')') {
            while (st.peek() != '(')
                result[k++] = st.pop();
            st.pop();
        } else {
            while (!st.isEmpty() && precedence(c) <= precedence(st.peek()))
                result[k++] = st.pop();
            st.push(c);
        }
    }

    while (!st.isEmpty())
        result[k++] = st.pop();

    result[k] = '\0';
    cout << result << endl;
    delete[] result;
}

int main() {
    char exp[100];
    cout << "Enter infix expression: ";
    cin >> exp;
    infixToPostfix(exp);
    return 0;
}
