#include <iostream>

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


int main()
{
    Stack<int> st(10);

    st.printStack();
    st.push(1);
    st.printStack();
    st.push(2);
    st.printStack();
    st.push(3);
    st.printStack();
    st.push(4);
    st.printStack();

    st.pop();
    st.printStack();
    st.pop();
    st.printStack();
    st.pop();
    st.printStack();


    return 0;
}