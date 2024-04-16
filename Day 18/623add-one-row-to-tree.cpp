class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d, bool isLeft = true) {
        if ( d == 1 )
        {
            TreeNode *left = isLeft? root : NULL, *right = isLeft? NULL : root;
            return new TreeNode(v, left, right);
        }
            
        if ( root )
        {
            root->left = addOneRow(root->left, v, d - 1);
            root->right = addOneRow(root->right, v, d - 1, false);
        }
            
        return root;
    }
};