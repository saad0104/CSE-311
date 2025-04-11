#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int i, int j)
{
    adj[i].push_back(j);
    adj[j].push_back(i);
}

bool isCyclicDFS(int node, int parent, vector<vector<int>> &adj, unordered_map<int, bool> &visited)
{
    visited[node] = 1;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool isCycleDetected = isCyclicDFS(neighbour, node, adj, visited);
            if (isCycleDetected)
            {
                return true;
            }
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &adj, int size)
{
    int n = adj.size(); // number of edges

    // to handle disconnected components
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, -1, adj, visited);
            if (ans == 1)
            {
                return "YES";
            }
        }
    }
    return "NO";
}

int main()
{
    int nodes = 10;
    vector<vector<int>> adj(nodes);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 5, 7);
    addEdge(adj, 7, 8);
    // addEdge(adj, 6, 8);
    addEdge(adj, 8, 9);

    cout << cycleDetection(adj, nodes);

    return 0;
}