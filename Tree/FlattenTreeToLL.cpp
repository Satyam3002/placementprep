class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

      
        flatten(root->left);
        flatten(root->right);

      
        if (root->left) {
            TreeNode* temp = root->right; 
            root->right = root->left;     
            root->left = nullptr;         

            TreeNode* t = root->right;
            while (t->right) t = t->right;

            
            t->right = temp;
        }
    }
};
