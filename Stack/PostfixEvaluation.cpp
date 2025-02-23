#include <bits/stdc++.h>
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(const string &postfix)
{
    stack<int> st;
    stringstream ss(postfix);
    string token;

    while (getline(ss, token, ','))
    {
        // If the token is an operand, push it to the stack
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) // Handle negative numbers
        {
            st.push(stoi(token)); // Convert string to int
        }
        // If the token is an operator, pop two operands from the stack, perform the operation, and push the result back
        else
        {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();

            switch (token[0])
            {
            case '+':
                st.push(val1 + val2);
                break;
            case '-':
                st.push(val1 - val2);
                break;
            case '*':
                st.push(val1 * val2);
                break;
            case '/':
                st.push(val1 / val2);
                break;
            case '^':
                st.push(pow(val1, val2));
                break;
            }
        }
    }

    // The result of the postfix expression is the only element left in the stack
    return st.top();
}

int main()
{
    string postfix = "5,6,2,+,*,12,4,/,-"; // Example postfix expression
    int result = evaluatePostfix(postfix);

    cout << "Postfix expression: " << postfix << endl;
    cout << "Evaluation result: " << result << endl;

    return 0;
}