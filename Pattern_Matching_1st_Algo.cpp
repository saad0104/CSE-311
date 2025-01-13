// First Pattern Matching Algorithm
// Slow Algortihm
// Naive Algorithm


#include <bits/stdc++.h>
using namespace std;

int PatternMatch(string p, string t)
{
    int r = p.length();
    int s = t.length();

    int k = 1;
    int max = s - r + 1;

    while (k <= max)
    {
        bool match = true;

        for (int i = 1; i < r; i++)
        {
            if (p[i - 1] != t[k + i - 2])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            return k;
        }
        k++;
    }

    return -1;
}

int main()
{
    string P, T;
    cin >> T >> P;

    cout << "at: " << PatternMatch(P, T) << endl;

    return 0;
}
