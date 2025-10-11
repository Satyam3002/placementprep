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
    void Solve(TreeNode *root, int &count, int &maxEle)
    {
        if (root == NULL)
        {
            return;
        }

        if (maxEle >= root->val)
        {
            count++;
        }
        maxEle = max(maxEle, root->val);

        Solve(root->left, count, maxEle);
        Solve(root->right, count, maxEle);
    }
    int goodNodes(TreeNode *root)
    {

        int count = 0;
        int maxEle = root->val;

        Solve(root, count, maxEle);
        return count;
    }
};