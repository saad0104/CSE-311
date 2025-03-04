#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

double price(double p, double r, double n)
{
    if (n == 1)
        return p;
    return p + price(p, r, n - 1);
}
int main()
{
    fastio();
    double p, r, n;
    p = 135;
    r = 51.68;
    n = 7;

    cout << price(p, r, n) << endl;

    return 0;
}