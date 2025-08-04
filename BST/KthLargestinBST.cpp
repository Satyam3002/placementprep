class Solution
{
public:
    int kthLargest(TreeNode *root, int &k)
    {
        if (root == NULL)
        {
            return -1;
        }

        int rightAns = kthLargest(root->right, k); // Go right first
        if (rightAns != -1)
        {
            return rightAns;
        }

        k--;
        if (k == 0)
        {
            return root->val;
        }

        int leftAns = kthLargest(root->left, k); // Then go left
        return leftAns;
    }
};
