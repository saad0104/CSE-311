#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int josephus(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return 2 * josephus(n / 2) - 1;
    }
    else
    {
        return 2 * josephus((n - 1) / 2) + 1;
    }
}

int main()
{
    fastio();

    cout << josephus(9) << endl;
    return 0;
}