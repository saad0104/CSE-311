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

    stack<char> st;
    queue<char> q;

    string str;
    getline(cin, str);

    for (int i = 0; i < str.size(); i++)
    {
        st.push(toupper(str.at(i)));
        q.push(toupper(str.at(i)));
    }
    int mis = 0;

    for(int i=0;i<str.size();i++)
    {
        if(st.top()!=q.front())
        {
            mis++;
        }
        st.pop();
        q.pop();
    }
    if(mis>0)
    {
        cout << "NOT Palindrome" << endl;
    }
    else{
        cout << "Palindrome" << endl;
    }

    return 0;
}