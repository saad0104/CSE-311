#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void count(int n)
{
    static int d = 1;
    cout << n << " ";
    cout << d << " ";
    d++;
    if (n > 1)
        count(n - 1);
    cout << d << " ";
}

int main()
{
    fastio();
    count(3);

    return 0;
}