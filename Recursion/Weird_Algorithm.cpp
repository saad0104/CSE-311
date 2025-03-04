#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<long long> seq(vector<long long> *vc, long long n)
{
    vc->push_back(n);

    if (n == 1)
    {
        // vc->push_back(n);
        return *vc;
    }
    if (n % 2 == 0)
    {
        n /= 2;
        // vc->push_back(n);
        return seq(vc, n);
    }
    else
    {
        n = n * 3 + 1;
        // vc->push_back(n);
        return seq(vc, n);
    }
}

void printvc(vector<long long> *vc)
{
    for (long long i = 0; i < vc->size(); i++)
    {
        cout << (*vc)[i] << " ";
    }
    cout << endl;
}

int main()
{
    fastio();
    long long n;
    cin >> n;
    vector<long long> vc;
    // cout << seq(&vc, n).size() << endl;
    seq(&vc, n);
    printvc(&vc);
    return 0;
}