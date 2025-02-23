#include <bits/stdc++.h>
using namespace std;

class Stack
{

    // 0 based array
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
    bool empty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack st(5);
    st.push(22);
    st.push(44);
    st.push(66);

    // cout << st.peek() << endl;

    // st.pop();

    // cout << st.peek() << endl;

    while(!st.empty())
    {
        cout << st.peek() << endl;
        st.pop();
    }
    return 0;
}