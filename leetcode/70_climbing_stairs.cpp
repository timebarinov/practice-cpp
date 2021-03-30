class Solution {
public:
    int climbStairs(int n) {
        int waysFor1stStep=0, waysFor2ndStep=1, total=0;
        for(int i=0; i<n; i++){
            if(i==0) {
                std::cout << waysFor1stStep;
            }
            if(i==1) {
                std::cout << waysFor2ndStep;
            }
            total = waysFor1stStep + waysFor2ndStep;
            waysFor1stStep = waysFor2ndStep;
            waysFor2ndStep = total;
            
        }
        return total;
    }
};

class Solution {
    public:
    int climbStairs(int n) {
    
        if(dp.find(n) != dp.end()){
            return dp.at(n);
        }
        
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        dp.insert(std::pair<int, int>(n-2, climbStairs(n-2)));
        dp.insert(std::pair<int, int>(n-1, climbStairs(n-1)));
        return dp.at(n-2) + dp.at(n-1);
        
    }    
    private:    
    map<int, int> dp;

};
