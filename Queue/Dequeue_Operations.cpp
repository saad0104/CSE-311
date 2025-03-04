// Dequeu STL

#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main()
{
    fastio();
    deque<int> dq;

    dq.push_back(1);
    dq.push_back(11);
    dq.push_front(111);
    dq.push_front(11111);
    dq.push_front(111111);

    auto it = dq.begin() + 2;
    dq.insert(it, 4); // inserting 4 in 3rd posittion

    cout << dq.front() << " " << dq.back() << endl;

    dq.pop_back();
    dq.pop_front();

    cout << dq.front() << " " << dq.back() << endl;

    for (auto it : dq)
    {
        cout << it << " ";
    }
    cout << endl;
    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << " ";
    }
    cout << endl;

    return 0;
}