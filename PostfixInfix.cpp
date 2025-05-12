#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

template <typename T>
class Stack {
    int top;
    int size;
    T* arr;

public:
    Stack(int size) {
        this->size = size;
        arr = new T[size];
        top = -1;
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

    T peek() {
        if (top == -1) {
            throw runtime_error("Stack is Empty");
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isMatchingParenthesis(const string& s) {
    int n = s.length();
    Stack<char> st(n);
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if(st.isEmpty()) return false;
            else if((s[i] == ')' && st.peek() == '(') ||
                    (s[i] == ']' && st.peek() == '[') ||
                    (s[i] == '}' && st.peek() == '{'))
                    {
                        st.pop();
                    }
            else return false;
        }
    }

    return st.isEmpty();
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(const string& infix) {
    Stack<char> st(infix.length());
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
            }
            st.pop(); // Pop '('
        } else { // Operator
            while (!st.isEmpty() && precedence(c) <= precedence(st.peek())) {
                postfix += st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        postfix += st.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& postfix) {
    Stack<int> st(postfix.length());

    for (char c : postfix) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int b = st.pop();
            int a = st.pop();

            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
                case '^': st.push(pow(a, b)); break;
                default: throw runtime_error("Invalid Operator");
            }
        }
    }

    return st.pop();
}

// Menu-driven program
int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Check Matching Parenthesis\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string expr;
                cout << "Enter the expression to check for matching parentheses: ";
                cin >> expr;
                if (isMatchingParenthesis(expr)) {
                    cout << "The parentheses are balanced.\n";
                } else {
                    cout << "The parentheses are not balanced.\n";
                }
                break;
            }
            case 2: {
                string infix;
                cout << "Enter the infix expression: ";
                cin >> infix;
                string postfix = infixToPostfix(infix);
                cout << "Postfix expression: " << postfix << endl;
                break;
            }
            case 3: {
                string postfix;
                cout << "Enter the postfix expression: ";
                cin >> postfix;
                try {
                    int result = evaluatePostfix(postfix);
                    cout << "The result of the postfix expression is: " << result << endl;
                } catch (exception& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
