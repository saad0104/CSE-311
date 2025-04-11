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

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl; // every level on seperate lines
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    cout << endl;
}


// Level Order Traversal Function
// void levelOrderTraversal(node* root) {
//     if (root == NULL) return;

//     queue<node*> q;
//     q.push(root);

//     while (!q.empty()) {
//         node* current = q.front();
//         q.pop();

//         cout << current->data << " ";

//         if (current->left) q.push(current->left);
//         if (current->right) q.push(current->right);
//     }

//     cout << endl;
// }


int main()
{

    node *root = NULL;

    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    levelOrderTraversal(root);

    return 0;
}