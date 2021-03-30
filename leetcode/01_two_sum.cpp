// find 2 numbers in vector sum of them = target
vector<int> twoSum(vector<int>& nums, int target) {
    
    for(int& i : nums){
        int first_index = (&i-&*(nums.begin()));            
        for(int& j : nums){
            int second_index = (&j-&*(nums.begin()));
            if((j+i)==target){
                return{first_index,second_index};
            }
        } 
    }
    return {};
}
