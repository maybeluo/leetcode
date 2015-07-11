class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 1) return 0;
        if(n < 2) return nums[0];
        
        vector<int> pos(n, 0), neg(n, 0);
        
        // rob 0-th house
        pos[0] = nums[0], neg[0] = 0;
        for(int i = 1; i < n -1; i++) {
            pos[i] = neg[i-1] + nums[i];
            neg[i] = max(neg[i-1], pos[i-1]);
        }
        int mx = max(pos[n-2], neg[n-2]);
        
        // do not rob 0-th house
        pos[0] = 0, neg[0] = 0;
        for(int i = 1; i < n; i++) {
            pos[i] = neg[i-1] + nums[i];
            neg[i] = max(neg[i-1], pos[i-1]);
        }
        mx = max(max(pos[n-1], neg[n-1]), mx);
        
        return mx;
    }
};
