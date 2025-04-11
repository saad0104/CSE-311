#include <bits/stdc++.h>
using namespace std;

void DFSrec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res)
{
    visited[s] = true;
    // cout << s << " ";
    res.push_back(s);
    for (auto i : adj[s])
    {
        if (!visited[i])
        {
            DFSrec(adj, visited, i, res);
        }
    }
}

vector<int> Dfs(vector<vector<int>> &adj, int s)
{
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    DFSrec(adj, visited, s, res);
    return res;
}

void addEdge(vector<vector<int>> &adj, int i, int j)
{
    adj[i].push_back(j);
    adj[j].push_back(i);
}

int main()
{
    vector<vector<int>> adj(4);

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 0);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    
    // Dfs(adj, 1);

    for (auto ans : Dfs(adj, 1))
    {
        cout << ans << " ";
    }
    return 0;
}