#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
bool isPalindrome(vector<int> vc, int front, int back)
{
    if (front == back)
    {
        return true;
    }
    if (vc[front] != vc[back])
    {
        return false;
    }
    if (front < back + 1)
    {
        return isPalindrome(vc, front + 1, back - 1);
    }
    return true;
}
int main()
{
    fastio();

    long long n;
    cin >> n;
    vector<int> vc;

    for (long long i = 0; i < n; i++)
    {
        long long q;
        cin >> q;
        vc.push_back(q);
    }
    cout << isPalindrome(vc, 0, n) << endl;

    return 0;
}
