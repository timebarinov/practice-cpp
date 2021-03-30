// find sub array largest sum ( kadane algo )
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        int sum_max = nums[0];
        int sum_cur = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            int n = nums[i];
            sum_cur = max(sum_cur + n, n);
            sum_max = max(sum_max, sum_cur);
        }
        return sum_max;
    }
};
