#include <bits/stdc++.h>
using namespace std;
int main()
{

string og, reversed;
cout << "Enter a String :" ;
cin >> og;

stack<char> st;

for(char ch : og)
{
    st.push(ch);
}

while(!st.empty())
{
    reversed += st.top();
    st.pop();
}

cout << "Reversed String : " << reversed << endl;


    return 0;
}