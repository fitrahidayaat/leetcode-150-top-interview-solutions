class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int start = prices[0], ans=0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > start) {
                ans += prices[i] - start;
            }
            start = prices[i];
        }
        
        return ans;
    }
};