// done

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
    int n, m;
    cin >> n >> m;
    int arr[n], arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> arr2[j];
    }

    vector<int> vc;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr2[i])
            {
                vc.push_back(arr[j]);
            }
        }
    }
    sort(vc.begin(), vc.end());
    auto it = unique(vc.begin(), vc.end());
    vc.erase(it, vc.end());

    for (auto it : vc)
    {
        cout << it << " ";
    }
    cout << endl;

    // set<int> st1;
    // set<int> st2;
    // set<int> st3;

    // for (int i = 0; i < n; i++)
    // {
    //     st1.insert(arr[i]);
    // }
    // for (int j = 0; j < m; j++)
    // {
    //     st2.insert(arr2[j]);
    // }

    // sort(st1.begin(), st1.end());
    // sort(st2.begin(), st2.end());


    // set_intersection(st1.begin(),st1.end(),
    //                           st2.begin(),st2.end(),back_inserter(st3));

    // cout << st3.size() << endl;

    return 0;
}