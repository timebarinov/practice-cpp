class Solution {
public:
    TreeNode* dfs(vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = (end + start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums, start, mid - 1);
        root->right = dfs(nums, mid + 1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
    
};