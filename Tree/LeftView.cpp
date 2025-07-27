#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Node class definition
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to create tree from input
Node *createTree()
{
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);
    root->left = createTree();
    root->right = createTree();

    return root;
}

void printLeftView(Node *root, int level, vector<int> &leftView)
{
    if (root == NULL)
        return;

    if (level == leftView.size())
    {
        // iska matlab left view ki node milgyi h , store karlo
        leftView.push_back(root->data);
    }
    printLeftView(root->left, level + 1, leftView);
    printLeftView(root->right, level + 1, leftView);
}

void printRightView(Node *root, int level, vector<int> &rightView)
{
    if (root == NULL)
        return;
    if (level == rightView.size())
    {
        rightView.push_back(root->data);
    }
    printRightView(root->right, level + 1, rightView);
    printRightView(root->left, level + 1, rightView);
}

int main()
{
    Node *root = createTree();
    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    vector<int> leftView;
    printLeftView(root, 0, leftView);
    for (int i = 0; i < leftView.size(); i++)
    {
        cout << leftView[i] << " ";
    }
    cout << endl;
    vector<int> rightView;
    printRightView(root, 0, rightView);
    for (int i = 0; i < rightView.size(); i++)
    {
        cout << rightView[i] << " ";
    }
    cout << endl;
    return 0;
}
