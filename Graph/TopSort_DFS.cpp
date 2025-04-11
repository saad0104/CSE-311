// using dfs

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}

void topSort(int node, vector<bool> &visited, stack<int> &st, vector<vector<int>> &adj)
{
    visited[node] = 1;
    for (auto neighbour : adj[node])
    {
        if (!visited[node])
        {
            // visited[neighbour] = 1;
            topSort(neighbour, visited, st, adj);
        }
    }
    st.push(node);
}

vector<int> dfsTopsort(vector<vector<int>> &adj, int size)
{
    vector<bool> visited(size, false);
    stack<int> st;
    vector<int> ans;

    for (int i = 1; i < size; i++)
    {
        if (!visited[i])
        {
            topSort(i, visited, st, adj);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int size = 7;
    vector<vector<int>> adj(size);

    // addEdge(adj, 0, 1);
    // addEdge(adj, 0, 3);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 3, 2);


    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 6);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);


    for (auto vc : dfsTopsort(adj, size))
    {
        cout << vc << " ";
    }
    cout << endl;

    return 0;
}