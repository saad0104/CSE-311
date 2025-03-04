#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

double shudCount(double n, double p)
{
    if (n == 0)
        return p;
    return 1.05 * shudCount(n - 1, p);
}
int main()
{
    fastio();
    double p = 10000, n = 30;
    // cin >> p >> n;

    cout << fixed << setprecision(2) << shudCount(n, p) << endl;

    return 0;
}