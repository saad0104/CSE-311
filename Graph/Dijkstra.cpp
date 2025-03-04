#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

class Graph
{

    int V;
    list<pair<int, int>> *adj;

public:
    Graph(int V);

    void addEdge(int u, int v, int w);

    pair<int, int> shortestPath(int source, int target);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
pair<int, int> Graph::shortestPath(int src, int tar)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return make_pair(tar, dist[tar]);
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    Graph g(node + 1);

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cout << g.shortestPath(1,3).first << "\t" << g.shortestPath(1,3).second << endl;

    return 0;
}