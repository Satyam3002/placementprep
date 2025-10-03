/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *CreateTree()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    Node *root = new Node(data);
    root->left = CreateTree();
    root->right = CreateTree();
    return root;
}

vector<vector<int>> Levelorder(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<Node *> q;
    q.push(root);
    vector<int> level;
    while (!q.empty())
    {

        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);

            level.push_back(node->data);
        }

        ans.push_back(level);
    }

    return ans;
}

void PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // NLR
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

int main()
{
    Node *root = CreateTree();
    PreOrder(root);
    cout << "Printing Level Order" << endl;
    Levelorder(root);

    return 0;
}