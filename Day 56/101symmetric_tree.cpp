class Solution {
public:
    bool isEqual(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        
        if (!left || !right || left->val != right->val)
            return false;
        
        return isEqual(left->left, right->right) && isEqual(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isEqual(root->left, root->right);
    }
};