#include <iostream>
#include <cstring> // for strlen, strcpy
#include <cctype>  // for isalnum
using namespace std;

const int MAX_SIZE = 100;

// Stack class
class Stack
{
private:
    char arr[MAX_SIZE];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_SIZE - 1; }

    void push(char ch)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = ch;
    }

    char pop()
    {
        if (isEmpty())
        {
            return '\0';
        }
        return arr[top--];
    }

    char peek()
    {
        if (isEmpty())
            return '\0';
        return arr[top];
    }
};

// Function Prototypes
int precedence(char op);
bool isOperator(char ch);
void displayMenu();
void infixToPostfix(char infix[], char postfix[]);

int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    int choice;

    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Infix Expression: ";
            cin.ignore(); // To clear any leftover newline
            cin.getline(infix, MAX_SIZE);
            break;

        case 2:
            if (strlen(infix) == 0)
            {
                cout << "Error: No infix expression entered. Please input first.\n";
                break;
            }
            infixToPostfix(infix, postfix);
            cout << "Postfix Expression: " << postfix << endl;
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
    cout << "1. Input Infix Expression\n";
    cout << "2. Convert to Postfix\n";
    cout << "0. Exit\n";
}

// Determine operator precedence
int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Check if character is operator
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Infix to Postfix conversion function
void infixToPostfix(char infix[], char postfix[])
{
    Stack s;
    int k = 0; // Index for postfix expression

    for (int i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];

        // If operand, add to output
        if (isalnum(ch))
        {
            postfix[k++] = ch;
        }

        // If '(', push to stack
        else if (ch == '(')
        {
            s.push(ch);
        }

        // If ')', pop until '('
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix[k++] = s.pop();
            }
            s.pop(); // Discard '('
        }

        // If operator
        else if (isOperator(ch))
        {
            while (!s.isEmpty() && s.peek() != '(' &&
                   precedence(s.peek()) >= precedence(ch))
            {
                postfix[k++] = s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.isEmpty())
    {
        postfix[k++] = s.pop();
    }

    postfix[k] = '\0'; // Null-terminate the postfix string
}