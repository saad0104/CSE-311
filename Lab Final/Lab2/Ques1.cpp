#include <bits/stdc++.h>
using namespace std;
stack<int> change(stack<int> st, int toDel)
{
    stack<int> st1;
    while (!st.empty())
    {
        st1.push(st.top());
        st.pop();
    }
    stack<int> st2;

    while (!st1.empty())
    {
        if (st1.top() != toDel)
        {
            st2.push(st1.top());
        }
        st1.pop();
    }
    return st2;
}
int main()
{

    stack<int> st;
    st.push(10);
    st.push(2);
    st.push(7);
    st.push(2);
    st.push(5);

    int toDel = 2;

    stack<int> stt = change(st, toDel);

    // cout << change(&st, toDel).size();

    while (!stt.empty())
    {
        cout << stt.top() << " ";
        stt.pop();
    }
    cout << endl;

    return 0;
}