#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int fibonacci(int n)
{
    if (n == 0 | n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main()
{
    fastio();
    int n;
    cin >> n;

    cout << fibonacci(n) << endl;

    return 0;
}