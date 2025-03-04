#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ;
}

void topsort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            topsort(neighbour, visited, s, adj);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    vector<bool> visited(v+1, false);
    stack<int> s;

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            topsort(i, visited, s, adj);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{
    fastio();

    int v = 6, e = 6; // Number of vertices and edges
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4},
        {4, 5},
        {4, 6}};

    vector<int> result = topologicalSort(edges, v, e);

    for(auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}