class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        
        int mx = prices[0], ans = 0;
        for(int i = 1; i < n; i++) {
            if(prices[i] > mx) {
                ans += (prices[i] - mx);// sell the stock bought before first
                mx = prices[i]; // buy again
            }
            else {
                mx = prices[i]; // buy the stock
            }
        }
        return ans;
    }
};
