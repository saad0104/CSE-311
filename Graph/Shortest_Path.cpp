// using bfs

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adjList, int i, int j)
{
    adjList[i].push_back(j);
    adjList[j].push_back(i);
}

// bfs

vector<int> ShortestPath(vector<vector<int>> &adjList, int s, int e)
{

    // bfs start
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto i : adjList[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    // bfs end

    vector<int> ans;

    int currentNode = e;
    ans.push_back(e);

    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// void displayList(vector<vector<int>> &adjList)
// {
//     for (int i = 0; i < adjList.size(); i++)
//     {
//         cout << i << " : ";
//         for (int v : adjList[i])
//         {
//             cout << v << " ";
//         }
//         cout << endl;
//     }
// }

int main()
{
    int size = 9;
    vector<vector<int>> adjList(size);

    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 5);
    addEdge(adjList, 3, 8);
    addEdge(adjList, 4, 6);
    addEdge(adjList, 6, 7);
    addEdge(adjList, 7, 8);
    addEdge(adjList, 5, 8);

    // displayList(adjList);

    for (int i : ShortestPath(adjList, 1, 8))
    {
        cout << i << " ";
    }

    return 0;
}