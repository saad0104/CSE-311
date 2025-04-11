#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}

bool checkcycle(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, vector<vector<int>> &adj)
{

    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = checkcycle(neighbour, visited, dfsVisited, adj);

            if (cycleDetected)
            {
                return true;
            }
        }
        else if (dfsVisited[neighbour])
        {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

bool isCycleDetected(vector<vector<int>> &adj, int size)
{
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 1; i < size; i++)
    {
        visited[i] = false;
        dfsVisited[i] = false;
    }

    for (int i = 1; i < size; i++)
    {
        if (!visited[i])
        {
            bool cycleFound = checkcycle(i, visited, dfsVisited, adj);
            if (cycleFound)
                return true;
        }
    }
    return false;
}

int main()
{
    int size = 9;
    vector<vector<int>> adj(size);

    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 7);
    addEdge(adj, 7, 8);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 4);
    addEdge(adj, 8, 7);

    cout << (isCycleDetected(adj, size) ? "YES" : "NO") << endl;
    return 0;
}