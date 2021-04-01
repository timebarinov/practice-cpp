class Solution {
public:
    // DFS
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        if(!root->left && root->right){
            return 1 + minDepth(root->right);
        }
        if(!root->right && root->left){
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left),minDepth(root->right));
        
    }
};

class Solution {
public:
    // BFS
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            depth++;
            // размер меняется
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                if (!node->left && !node->right) {
                    return depth;
                }
            }
        }
        return depth;
    }
};

