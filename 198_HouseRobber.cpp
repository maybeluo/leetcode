class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 1) return 0;
        
        vector<int> pos(n, 0), neg(n, 0);
        pos[0] = nums[0];
        
        for(int i = 1; i < n; i++) {
            pos[i] = neg[i-1] + nums[i]; // rob i-th house
            neg[i] = max(neg[i-1], pos[i-1]); // do not rob i-th house
        }
        
        return max(pos[n-1], neg[n-1]);
        
    }
};
