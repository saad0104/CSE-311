#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int movesReq(int n)
{
    if (n == 0)
        return 0;
    return 2 * movesReq(n - 1) + 1;
}
int main()
{
    fastio();

    cout << movesReq(3) << endl;

    return 0;
}