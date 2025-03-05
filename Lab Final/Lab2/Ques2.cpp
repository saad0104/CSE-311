#include <bits/stdc++.h>
using namespace std;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string reverseVowels(string str) {
    stack<char> vowels;
    queue<int> positions;

    for (int i = 0; i < str.size(); i++) {
        if (isVowel(str[i])) {
            vowels.push(str[i]);
            positions.push(i);
        }
    }

    while (!positions.empty()) {
        int pos = positions.front();
        positions.pop();
        str[pos] = vowels.top();
        vowels.pop();
    }

    return str;
}

int main() {
    fastio();

    string str;
    // cin >> str;
    str = "hello world";

    cout << reverseVowels(str) << endl;

    return 0;
}