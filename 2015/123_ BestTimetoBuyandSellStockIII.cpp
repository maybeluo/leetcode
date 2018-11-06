// maximum value must be on the RIGHT hand of minimum value.
// thus, we need to record minimum value from 0 to n-1, while record maximum value from n-1 to 0.

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        
        vector<int> leftProfit(n, 0), rightProfit(n, 0);
        
        // profit from 0 to i
        int mx = prices[0];
        for(int i = 1; i < n; i++) {
            mx = min(prices[i], mx);
            leftProfit[i] = max(leftProfit[i-1], prices[i] - mx);
        }
        
        // profit from i to n-1
        mx = prices[n-1];
        for(int i = n-2; i >= 0; i--) {
            mx = max(prices[i], mx);
            rightProfit[i] = max(mx - prices[i], rightProfit[i+1]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, leftProfit[i] + rightProfit[i] );
        }
        
        return ans;
    }
};
