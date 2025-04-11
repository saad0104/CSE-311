#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}

vector<int> topSortbfs(vector<vector<int>> &adj, int size)
{
    vector<int> indegree;
    // indegree count
    for (auto i : adj)
    {
        for (auto j : i)
        {
            indegree[j]++;
        }
    }
    // pushing 0 indegree
    queue<int> q;

    for (int i = 0; i < size; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    // do bfs
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}

int main()
{
    int size = 6;
    vector<vector<int>> adj(size);

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 5);
    addEdge(adj, 5, 4);

    for (auto it : topSortbfs(adj, size))
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}