#include <bits/stdc++.h>
using namespace std;
int LinesinthePlane(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return LinesinthePlane(n - 1) + n;
}
int main()
{
    int n = 5;
    cout << LinesinthePlane(n) << endl;
    return 0;
}