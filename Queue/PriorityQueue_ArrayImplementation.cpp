#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct item
{
    int value;
    int priority;
};
item pr[100000];   int size = -1;

void enqueue(int value, int priority)
{
    size++;
    pr[size].value = value;
    pr[size].priority = priority;
}

int peek()
{
    int highestPriority = INT_MIN;
    int ind = -1;  // index of the peek element

    for (int i = 0; i <= size; i++)
    {
        if (highestPriority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value)
        {
            highestPriority = pr[i].priority;
            ind = i;
        }
        else if (highestPriority < pr[i].priority)
        {
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}
void dequeu()
{
    int ind = peek();
    for(int i=ind;i<size;i++)
    {
        pr[i] = pr[i+1];
    }
    size--;

}


int main()
{
    fastio();

    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(16, 4);
    enqueue(12, 3);

    int ind = peek();
    cout << ind << endl;  // index of the element with the highest priority (here 4)
    cout << pr[ind].value << endl;  // element with the highest priority. 14 and 16 has the same priority. As 16 is greater, highest element is 16.

dequeu();

ind = peek();
cout << peek() << endl;
cout << pr[ind].value << endl;
    return 0;
}