class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 1) return 0;
        
        int mx = 0x5fffffff, ans = 0 - 0x7fffffff;
        for(int i = 0; i < n; i++) {
            mx = min(mx, prices[i]);
            ans = max(ans, prices[i] - mx);
        }
        return ans;
    }
};
