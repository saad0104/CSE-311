#include <bits/stdc++.h>
using namespace std;

int Josephus(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    return (Josephus(n - 1, k) + k) % n;
}

int main()
{
    int n, k;
    // cin >> n >> k;
    n = 9;
    k = 2;
    cout << Josephus(n, k) + 1 << endl;
    // + 1 for 1 based indexing

    return 0;
}