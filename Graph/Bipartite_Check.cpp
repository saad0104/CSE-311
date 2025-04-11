// using BFS
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int i, int j)
{
    adj[i].push_back(j);
    adj[j].push_back(i);
}

bool checkBP(int start, int size, vector<vector<int>> &adj, vector<int> &color)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool ifBipartite(vector<vector<int>> &adj, int size)
{
    vector<int> color(size, -1);

    for (int i = 0; i < size; i++)
    {
        if (color[i] == -1)
        {
            if (checkBP(i, size, adj, color) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int size = 7;
    vector<vector<int>> adj(7);

    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);

    cout << (ifBipartite(adj, size) ? "YES" : "NO") << endl;

    return 0;
}