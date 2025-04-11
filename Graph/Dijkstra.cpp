// babbar

#include <bits/stdc++.h>
using namespace std;

void addEdge(unordered_map<int, list<pair<int, int>>> &adj, int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

vector<int> Dijkstra(unordered_map<int, list<pair<int, int>>> &adj, int size, int source)
{
    vector<int> dist(size, INT32_MAX);
    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        // fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove top record
        st.erase(st.begin());

        // traverse top neighbours

        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // if record found
                if (record != st.end())
                {
                    st.erase(record);
                }

                // distance update

                dist[neighbour.first] = nodeDistance + neighbour.second;

                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

int main()
{

    int size = 5;
    int source = 0;
    unordered_map<int, list<pair<int, int>>> adj;

    addEdge(adj, 2, 1, 3);
    addEdge(adj, 2, 0, 1);
    addEdge(adj, 1, 0, 7);
    addEdge(adj, 1, 3, 5);
    addEdge(adj, 1, 4, 1);
    addEdge(adj, 3, 4, 7);
    addEdge(adj, 0, 3, 2);

    for (auto it : Dijkstra(adj, size, source))
    {
        cout << it << " ";
    }

    return 0;
}