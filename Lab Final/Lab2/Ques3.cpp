#include <bits/stdc++.h>
using namespace std;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

string change(string st, char x, char y, int i = 0) {
    if (i == st.size()) {
        return st;
    }
    if (st[i] == x) {
        st[i] = y;
    }
    return change(st, x, y, i + 1);
}

int main() {
    fastio();

    string str;
    char x, y;
    // cin >> str;
    // cin >> x >> y;
    str = "abacd";
    x = 'a';
    y = 'x';

    cout << change(str, x, y) << endl;

    return 0;
}
