#include <bits/stdc++.h>
using namespace std;

string LCS(string &st1, string &st2)
{
    int m = st1.size();
    int n = st2.size();

    // A (m+1 * n+1) 2d vector filled with 0s.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (st1[i - 1] == st2[j - 1])
            {
                // If matches, value is 1 up to the diagonal cell.
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                // If doesn't matches, value is maximum of the adjacent cells.
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // return dp[m][n];

    int index = dp[m][n];

    if (index > 0)
    {
        char subseq[index + 1];
        subseq[index] = '\0';

        int i = m, j = n;
        while (i > 0 && j > 0)
        {
            if (st1[i - 1] == st2[j - 1])
            {
                subseq[index - 1] = st1[i - 1];
                i--;
                j--;
                index--;
            }

            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
                j--;
        }

        return subseq;
    }
    else
    {
        return "No LCS";
    }
}

int main()
{
    string st1 = "abcde";
    string st2 = "fghij";

    cout << "LCS is : " << LCS(st1, st2) << endl;

    return 0;
}