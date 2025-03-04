#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << from_rod << " " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
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
    int n;
    cin >> n;
    cout << movesReq(n) << endl;
    towerOfHanoi(n, '1', '3', '2');

    return 0;
}