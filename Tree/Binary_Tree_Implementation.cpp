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

// Tree Building Using Recursion
//  node *buildTree(node *root)
//  {
//      cout << "Enter the data -> " << endl;
//      int data;
//      cin >> data;
//      root = new node(data);
//      if (data == -1)
//      {
//          return NULL;
//      }
//      cout << "Inserting on the Left of " << data << endl;
//      root->left = buildTree(root->left);
//      cout << "Inserting on the Right of " << data << endl;
//      root->right = buildTree(root->right);

//     return root;
// }

// TRee building using Level Order (Iterative)
void buildFromLevelOrder(node *&root)
{
    queue<node *> q;

    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void Preorder(node *root) // NLR
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

int main()
{

    node *root = NULL;

    // root = buildTree(root);
    buildFromLevelOrder(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    Preorder(root);

    return 0;
}