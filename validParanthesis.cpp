#include <iostream>
#include <stack>

using namespace std;

template <class T>
class Stack
{
    int top;
    int size;
    T *arr;
public:
    Stack(int size)
    {
        this->size = size;
        arr = new T[size];
        this->top = -1;
    }

    void push(T n)
    {
        if(top == size-1)
        {
            std::cout << "Stack is Full\n";
            return;
        }
        top++;
        arr[top] = n;
    }

    T pop()
    {
        if(top == -1)
        {
            std::cout << "Stack is Empty\n";
            throw std::underflow_error("Stack UnderFlow");
        }
        T temp = arr[top];
        top--;
        return temp;
    }

    bool isEmpty()
    {
        if(top == -1) return true;
        return false;
    }

    T peek()
    {
        return arr[top];
    }

    void printStack()
    {
        if (isEmpty())
        {
            std::cout << "Stack is Empty\n";
            return;
        }

        for (int i = top; i >= 0; i--) // Start from top and go down to index 0
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

bool validParanthesis(string s)
{
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

int main()
{
    string s;
    cout << "Enter Paranthesis to Check(only '(, ), {, }, [, ]'): ";
    cin >> s;

    cout << (validParanthesis(s) ? "Valid\n" : "Not Valid\n");
    return 0;
}   