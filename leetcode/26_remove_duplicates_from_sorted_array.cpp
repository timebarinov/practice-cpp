// remove duplicate from vector
int removeDuplicates(vector<int>& nums) {
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
}