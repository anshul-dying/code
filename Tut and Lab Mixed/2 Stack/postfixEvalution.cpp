#include <iostream>
#include <cstring> // For strlen
#include <cctype>  // For isdigit
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

// Stack class
class Stack
{
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_SIZE - 1; }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Error: Not enough operands.\n";
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
            return -1;
        return arr[top];
    }
};

// Function Prototypes
void displayMenu();
int evaluatePostfix(char postfix[]);
int applyOperator(int a, int b, char op);
bool isValidPostfix(char expr[]);

int main()
{
    char postfix[MAX_SIZE];
    int choice;
    int result;

    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Postfix Expression (single-digit operands only): ";
            cin.ignore(); // To clear any leftover newline
            cin.getline(postfix, MAX_SIZE);

            if (!isValidPostfix(postfix))
            {
                cout << "Invalid input. Only digits and operators (+, -, *, /, ^) allowed.\n";
                break;
            }
            break;

        case 2:
            if (strlen(postfix) == 0)
            {
                cout << "Error: No postfix expression entered. Please input first.\n";
                break;
            }
            result = evaluatePostfix(postfix);
            if (result != -1) // Only print if no error occurred
                cout << "Result: " << result << endl;
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

// Display menu options
void displayMenu()
{
    cout << "1. Input Postfix Expression\n";
    cout << "2. Evaluate Postfix Expression\n";
    cout << "0. Exit\n";
}

// Check if expression contains only valid characters
bool isValidPostfix(char expr[])
{
    for (int i = 0; i < strlen(expr); i++)
    {
        char ch = expr[i];
        if (!(isdigit(ch) || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == ' '))
            return false;
    }
    return true;
}

// Evaluate Postfix expression
int evaluatePostfix(char postfix[])
{
    Stack s;
    int result = 0;

    for (int i = 0; i < strlen(postfix); i++)
    {
        char ch = postfix[i];

        if (ch == ' ')
            continue;

        if (isdigit(ch))
        {
            s.push(ch - '0'); // Convert char to int
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            if (s.isEmpty())
            {
                cout << "Error: Insufficient operands.\n";
                return -1;
            }
            int b = s.pop();

            if (s.isEmpty())
            {
                cout << "Error: Insufficient operands.\n";
                return -1;
            }
            int a = s.pop();

            int res = applyOperator(a, b, ch);
            if (res == -1 && ch == '/')
            {
                return -1; // division by zero
            }
            s.push(res);
        }

        else
        {
            cout << "Error: Invalid character found: " << ch << endl;
            return -1;
        }
    }

    if (s.isEmpty())
    {
        cout << "Error: No result found. Expression may be empty or invalid.\n";
        return -1;
    }

    result = s.pop();

    if (!s.isEmpty())
    {
        cout << "Warning: Extra values left in stack. Invalid expression?\n";
        return -1;
    }

    return result;
}

// Apply operator based on type
int applyOperator(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            cout << "Error: Division by zero.\n";
            return -1;
        }
        return a / b;
    case '^':
        return pow(a, b);
    default:
        cout << "Invalid operator: " << op << endl;
        return -1;
    }
}