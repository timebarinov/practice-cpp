class Solution {
public:    
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (abs(getH(root->left) - getH(root->right)) > 1) {
            return false;
        } 
        else {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }

    int getH(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftH = getH(root->left);
        int rightH = getH(root->right);
        return max(leftH, rightH) + 1;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getH(root) != -1;
    }

    int getH(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftH = getH(root->left);
        if (leftH == -1) {
            return -1;
        }
        int rightH = getH(root->right);
        if (rightH == -1) {
            return -1;
        }
        if (abs(leftH - rightH) > 1) {
            return -1;
        }
        return max(leftH, rightH) + 1;
    }
};