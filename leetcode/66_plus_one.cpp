// plus decimal
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size();
        while(idx--){
            if(digits[idx] == 9){
                digits[idx] = 0;
            }
            else {
                ++digits[idx];
                return digits;
            }
        }
        // если все девятки то петля заканчивается и вставляет 1 в начало
        digits.insert(digits.begin(), 1);
        return digits;
    }            
};
