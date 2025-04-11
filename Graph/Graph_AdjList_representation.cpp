// C++ program to demonstrate Adjacency List
// representation of undirected and unweighted graph
#include <iostream>
#include <vector>
using namespace std;

// class graph
// {
// public:
//     vector<vector<int>> adj;

//     void addEdge(int u, int v, bool dir)
//     {
//         adj[u].push_back(v);
//         if (dir == 0)
//         {
//             adj[v].push_back(u);
//         }
//     }
//     int size()
//     {
//         return adj.size();
//     }
//     void printAdjList()
//     {
//         for (int i = 0; i < adj.size(); i++)
//         {
//             cout << i << "-> ";
//             for (auto j : adj[i])
//             {
//                 cout << j << " ";
//             }
//             cout << endl;
//         }
//     }
// };


// Function to add an edge between two vertices
void addEdge(vector<vector<int>> &adj, int i, int j)
{
    adj[i].push_back(j);
    adj[j].push_back(i); // Undirected
}

// Function to display the adjacency list
void displayAdjList(const vector<vector<int>> &adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        cout << i << ": "; // Print the vertex
        for (int j : adj[i])
        {
            cout << j << " "; // Print its adjacent
        }
        cout << endl;
    }
}

// Main function
int main()
{
    // Create a graph with 4 vertices and no edges
    int V = 4;
    vector<vector<int>> adj(V);

    // Now add edges one by one
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj);


    // Class Implementation Not working
    // graph g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(0, 2, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(2, 3, 0);
    // g.addEdge(2, 4, 0);
    // g.addEdge(2, 4, 0);

    // cout << g.size();

    // g.printAdjList();

    return 0;
}
