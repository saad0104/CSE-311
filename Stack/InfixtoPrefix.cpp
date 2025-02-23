#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> st;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Function to reverse a string
string reverseString(const string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

// Function to convert infix expression to prefix expression
string infixToPrefix(const string& infix) {
    string reversedInfix = reverseString(infix);
    for (char& ch : reversedInfix) {
        if (ch == '(') {
            ch = ')';
        } else if (ch == ')') {
            ch = '(';
        }
    }

    string postfix = infixToPostfix(reversedInfix);
    string prefix = reverseString(postfix);

    return prefix;
}

int main() {
    string infix = "(a-b/c)*(a/k-l)";
    string prefix = infixToPrefix(infix);

    cout << "Infix expression: " << infix << endl;
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}