#include <bits/stdc++.h>
using namespace std;

// Function to process the string with backspaces
string processString(string s) {
    queue<char> q;
    for (char ch : s) {
        if (ch == '#') {
            if (!q.empty()) {
                q.pop();  // Remove last inserted character (simulate backspace)
            }
        } else {
            q.push(ch);
        }
    }
    
    // Convert queue to a string
    string result = "";
    while (!q.empty()) {
        result += q.front();
        q.pop();
    }
    return result;
}

// Function to check if processed versions of s1 and s2 are equal
bool areEqualAfterProcessing(string s1, string s2) {
    return processString(s1) == processString(s2);
}

// Main function
int main() {
    string s1 = "geee#e#ks";
    string s2 = "gee##eeks";

    cout << (areEqualAfterProcessing(s1, s2) ? "True" : "False") << endl;

    s1 = "equ#ual";
    s2 = "ee#quaal#";
    
    cout << (areEqualAfterProcessing(s1, s2) ? "True" : "False") << endl;

    return 0;
}
