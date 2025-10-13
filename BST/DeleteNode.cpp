/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // find Node
        if (root == NULL)
        {
            return NULL;
        }

        // if key > root -> val
        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        // if val > key
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            // 4 cases
            // 1. No Child
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            // 2.left NULL
            else if (!root->left)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            // 3.right NULL
            else if (!root->right)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                TreeNode *successor = FindMin(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }

    TreeNode *FindMin(TreeNode *node)
    {

        while (node->left != NULL)
        {
            node = node->left;
        }

        return node;
    }
};