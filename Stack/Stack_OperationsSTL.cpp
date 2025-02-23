#include <bits/stdc++.h>
using namespace std;
int main()
{

//declaration
stack<int> st;
stack<int> st2;

//empalce()
st.emplace(2);
st.push(3);
st.push(4);
st.push(5);
st.push(6);

// push()
st2.push(7);
st2.push(77);
st2.push(777);
st2.push(7777);
st2.push(777777);

// swap()
st.swap(st2);  // swaps elements of two stacks

// empty()
while(!st.empty())
{
    // top() , size(), pop()
    cout << st.top() << " " << st.size()<< endl;
    st.pop();
}

    return 0;
}


// emplace is similar to push. It inserts an element on top.
//  emplace can be more efficient in certain situations where the element being inserted is complex or expensive to copy.