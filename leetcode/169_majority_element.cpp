class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int majority = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                count++;
                majority = nums[i];
            } 
            else if (nums[i] == majority) {
                count++;
            } 
            else {
                count--;
            }
        }
      return majority;
    } 
};

//bit manipulation
class Solution {
    public:
    int majorityElement(vector<int>& nums) {
        // в int 32 бита
        array<int, 32> bit {};
        for (int num : nums) {
            for (int i = 0; i < bit.size(); i++) {
                if ((num >> (31 - i) & 1) == 1) {
                    bit[i]++;
                }
            }
        }
        int res = 0;        
        for (int i = 0; i < bit.size(); i++) {            
            bit[i] = bit[i] > nums.size() / 2 ? 1 : 0;
            res += bit[i] * (1 << (31 - i));
        }
        return res;
    }
};

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    array<int, sizeof(int) *8> bit {};
    for(auto num : nums) {
        for(int i = 0; i < bit.size(); ++i) {
            if(num & (1 << i)) {
                ++bit[i];
            }
        }
    }

    int majority {};
    for(int i = 0; i < bit.size(); ++i) {
        if(bit[i] > nums.size() / 2) {
            majority |= 1 << i;
        }
    }
    return majority;
  }
};