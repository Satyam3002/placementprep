/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftheight = minDepth(root->left);
        int rightheight = minDepth(root->right);
        if (leftheight == 0 || rightheight == 0)
            return leftheight + rightheight + 1;
        int finalans = min(leftheight, rightheight) + 1;

        return finalans;
    }
};