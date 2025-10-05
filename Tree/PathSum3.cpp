//  PathSum3.cpp
// solve this using two recursive functions
// one function to traverse each node and another function to find the path sum from that node
// Tc -> O(N^2) in worst case
// Sc -> O(H) height of the tree
class Solution
{
public:
    void Solve(TreeNode *root, long long sum, int targetSum, long long &count)
    {
        if (root == NULL)
        {
            return;
        }
        sum += root->val;

        if (sum == targetSum)
        {
            count++;
        }

        Solve(root->left, sum, targetSum, count);
        Solve(root->right, sum, targetSum, count);
    }

    void Outer(TreeNode *root, long long sum, int targetSum, long long &count)
    {
        if (root == NULL)
        {
            return;
        }
        Solve(root, 0, targetSum, count);
        Outer(root->left, 0, targetSum, count);
        Outer(root->right, 0, targetSum, count);
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        long long sum = 0;
        long long count = 0;

        Outer(root, sum, targetSum, count);
        return count;
    }
};

// Optimized approach using hashmap to store the prefix sum
// Tc -> O(N)
// Sc -> O(N) for hashmap

class Solution
{
public:
    void Solve(TreeNode *root, long long sum, int targetSum, long long &count)
    {
        if (root == NULL)
        {
            return;
        }
        sum += root->val;

        if (sum == targetSum)
        {
            count++;
        }

        Solve(root->left, sum, targetSum, count);
        Solve(root->right, sum, targetSum, count);
    }

    void Outer(TreeNode *root, long long sum, int targetSum, long long &count)
    {
        if (root == NULL)
        {
            return;
        }
        Solve(root, 0, targetSum, count);
        Outer(root->left, 0, targetSum, count);
        Outer(root->right, 0, targetSum, count);
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        long long sum = 0;
        long long count = 0;

        Outer(root, sum, targetSum, count);
        return count;
    }
};