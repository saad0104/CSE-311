// C++ program to demonstrate Adjacency Matrix
// representation of directed and weighted graph
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &mat, int i, int j, int x)
{
    mat[i][j] = x;
}

void displayMatrix(vector<vector<int>> &mat)
{
    int V = mat.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main()
{

    // Create a graph with 4 vertices and no edges
    // Note that all values are initialized as 0
    int V = 4;
    vector<vector<int>> mat(V, vector<int>(V, INFINITY));   // Creats a matrix mat with size V ans rows of vector size of V with all elements 0. v*v size matrix.


    // Now add edges one by one
    addEdge(mat, 0, 1, 10);
    addEdge(mat, 0, 2, 7);
    addEdge(mat, 1, 2, 9);
    addEdge(mat, 2, 3, 76);
    addEdge(mat, 3, 2, 67);


    cout << "Adjacency Matrix Representation" << endl;
    displayMatrix(mat);

    return 0;
}
