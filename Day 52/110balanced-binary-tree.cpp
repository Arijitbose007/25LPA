class Solution {
public:
    int solve(TreeNode* root){
        if(!root) return 0;
        int leftHeight=solve(root->left);
        if(leftHeight == -1) return -1;
        
        int rightHeight=solve(root->right);
        if(rightHeight==-1) return -1;
        
        if(!(abs(leftHeight-rightHeight)<=1)) return -1;
        return max(leftHeight,rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        return solve(root) !=-1;
    }
};