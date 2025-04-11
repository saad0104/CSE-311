#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main()
{
    fastio();

    long long n;
    cin >> n;
    vector<long long> vc;

    for (long long i = 0; i < n; i++)
    {
        long long q;
        cin >> q;
        vc.push_back(q);
    }
    vector<long long> f(n, -1);
    for (long long i = 0; i < n - 1; i++)
    {
        for (long long j = i + 1; j < n; j++)
        {
            if (vc[i] < vc[j])
            {
                f[i] = vc[j];
                break;
            }
        }
    }

    for (long long i = 0; i < f.size(); i++)
    {
        cout << f[i] << " ";
    }
    cout << endl;
    return 0;
}