#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int i, int j)
{
    adj[i].push_back(j);
    adj[j].push_back(i);
}

bool isCyclicBFS(vector<vector<int>> &adj, int src, unordered_map<int, bool> &visited)
{

    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = 1;
    queue<int> q; // parent check
    q.push(src);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbours : adj[front])
        {
            if (visited[neighbours] == true && neighbours != parent[front])
            {
                return true;
            }
            else if (!visited[neighbours])
            {
                q.push(neighbours);
                visited[neighbours] = 1;
                parent[neighbours] = front;
            }
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
            bool ans = isCyclicBFS(adj, i, visited);
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
    addEdge(adj, 6, 8);
    addEdge(adj, 8, 9);

    cout << cycleDetection(adj, 4);

    return 0;
}