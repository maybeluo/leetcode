
class Solution {
public:
    int getProfit(vector<int>&v, int l, int r) {
        int ans = 0;
        for(int i = l + 1; i <= r; i++) {
            ans += max(0, v[i] - v[i-1]);
        }
        return ans;
    }

    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
    	if(k < 1 || n < 2) return 0;
    	if(k >= n) return getProfit(prices, 0, n-1);
    	//pos: has transactions at the i-th day
    	vector<int> pos(k + 1, 0), neg(k + 1, 0);
    	
    	for(int i = 2; i <= n; i++) {
    	    int diff = prices[i-1] - prices[i-2];
    	    for(int j = k; j >= 1; j--) {
    	        neg[j] = max(neg[j], pos[j]);
    	        
    	        // max(0,diff): buy and sell the stock at the same day.
    	        pos[j] = max(pos[j] + diff, neg[j-1] + max(0, diff)); 
    	    }
    	}

    	return max( pos[k], neg[k]);
    }
    
};
