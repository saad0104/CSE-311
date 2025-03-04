#include <bits/stdc++.h>
using namespace std;

string removeAdjacentDuplicates(string str) {
    queue<char> q;
    for (char ch : str) {
        if (!q.empty() && q.back() == ch) {
            q.pop();  // Remove adjacent duplicate
        } else {
            q.push(ch);
        }
    }
    
    // Reconstruct the result from the queue
    string result = "";
    while (!q.empty()) {
        result += q.front();
        q.pop();
    }
    
    return result;
}

int main() {
    string str1 = "azxxzy";
    string str2 = "aaccdd";
    
    cout << "Output: " << removeAdjacentDuplicates(str1) << endl;
    cout << "Output: " << removeAdjacentDuplicates(str2) << endl;
    
    return 0;
}
