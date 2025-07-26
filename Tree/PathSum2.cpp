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
    void Solve(TreeNode *root, int sum, int targetSum, vector<int> temp, vector<vector<int>> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == targetSum)
            {
                ans.push_back(temp);
            }
            else
            {
                return;
            }
        }
        Solve(root->left, sum, targetSum, temp, ans);
        Solve(root->right, sum, targetSum, temp, ans);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        Solve(root, sum, targetSum, temp, ans);
        return ans;
    }
};