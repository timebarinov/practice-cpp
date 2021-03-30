class Solution {
public:
int maxProfit(vector<int>& prices) {
        int pro = 0;
            for (int i = 0; i < prices.size() - 1; i++) {
                if (prices[i + 1] > prices[i]) {
                    pro += prices[i + 1] - prices[i];
                }
            }
            return pro;
        }
};

class Solution {
public:
int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int res=0;
    
        if(len==0||len==1) {
            return 0;
        }
        
        for(int i=0;i<len-1;i++) {
            if(prices[i]<prices[i+1])
                res+=prices[i+1]-prices[i];
        }
        
        return res;
    }

};