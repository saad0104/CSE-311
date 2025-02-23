#include <bits/stdc++.h>
using namespace std;
int main()
{

    queue<int> q;
    queue<int> q2;

    q.emplace(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    // push()
    q2.push(7);
    q2.push(77);
    q2.push(777);
    q2.push(7777);
    q2.push(777777);

    // swap()
    q.swap(q2); // swaps elements of two qacks

    // empty()
    while (!q.empty())
    {
        // front() , size(), pop(), back()
        cout << q.front() << " " << q.size() << " " << q.back() << endl;
        q.pop();
    }

    return 0;
}
