#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data -> " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Inserting on the Left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Inserting on the Right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void Inorder(node *root, int &count) // NLR
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left, count);
    // cout << root->data << " ";
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    Inorder(root->right, count);
}

int LeafNodeCount(node *root)
{
    int count = 0;
    Inorder(root, count);
    return count;
}
int main()
{

    node *root = NULL;

    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Total Leaf Node : ";
    cout << LeafNodeCount(root);
    return 0;
}