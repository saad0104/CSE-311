#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    };

    void enque(int data)
    {
        if (rear == size)
        {
            cout << "Overflow" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }
    int deque()
    {
        if (front == rear)
        {
            // cout << "Underflow" << endl;
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    bool empty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int Front()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};

int main()
{

    Queue q(5);
    q.enque(500);
    q.enque(600);
    q.enque(700);
    q.enque(800);
    // cout << q.Front() << endl;

    // q.deque();

    // cout << q.Front() << endl;

    while (!q.empty())
    {
        cout << q.Front() << endl;
        q.deque();
    }

    return 0;
}