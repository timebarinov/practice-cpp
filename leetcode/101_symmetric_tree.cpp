// check symmetric tree
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* p, TreeNode* q){    
        return p == q 
        || (p && q && p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left));
    }
};