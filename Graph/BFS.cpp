#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int i, int j)
{
    adj[i].push_back(j);
    adj[j].push_back(i);
}

vector<int> BFS(vector<vector<int>> &adj, int s)
{
    int ss = adj.size();
    queue<int> q;
    vector<int> res;
    vector<bool> visited(ss, false);

    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // cout << cur << " ";
        res.push_back(cur);
        for (int x : adj[cur])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> adj(4);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 4);

    for (auto ans : BFS(adj, 0))
    {
        cout << ans << " ";
    }

    return 0;
}