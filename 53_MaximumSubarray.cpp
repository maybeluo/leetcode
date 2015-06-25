// Dynamic Programming.
// dislike Longest Increasing Subarray.
// dp[i]: maxmium subarray end WITH element i (continuous subarray, thus WITH is reasonable.)
//  dp[i] = max(nums[i], dp[i-1] + nums[i])

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 1) return 0;
        
        int dp[n + 10];
        memset(dp, 0, (n+10)*sizeof(int) );
        dp[0] = nums[0];
        int mx = dp[0];
        for(int i = 1; i < n; i++){
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};
