// tree path sum
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {  
        if (!root) {
            return false;
        }
        else if(root->val == targetSum && root->left == nullptr && root -> right == nullptr) {
            return true;
        } else {
            int tmp = targetSum - root->val;
            return hasPathSum(root->left, tmp) || hasPathSum(root->right, tmp);
        }    
        
    }
};
