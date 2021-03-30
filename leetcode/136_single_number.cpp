// XOR bit 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        // i XOR i XOR a = 0 XOR a = a;
        for (int i : nums) {
        a ^= i;
        }
        return a;
  }

};