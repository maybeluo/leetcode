// TLE a few times.
// Then I realize that I can only update the elements whose distance are larger than the current maximum, see L19-L22.
// O(n^2) --> O(n)

class Solution {
public:
    int jump(vector<int>& nums) {
        const int maxInt = 0x5fffffff;
        int n = nums.size();
        assert(n >= 1);
        
        int dp[n + 10];
        for(int i = 0; i < n + 10; i++)
            dp[i] = maxInt;
        dp[0] = 0;
        
        int mx = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] + i > mx){ // only update the elements whose distance are larger than mx
                for(int j = mx + 1; j < n && j <= i + nums[i] ; j++) {
                    dp[j] = min(dp[j], dp[i] + 1);
                }
                mx = nums[i] + i;
            }
            if( dp[n-1] < maxInt ) return dp[n-1];
        }
        
        if( dp[n-1] < maxInt ) return dp[n-1];
        else return -1; 
    }
};
