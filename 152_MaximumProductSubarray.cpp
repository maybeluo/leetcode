// L14   L16

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pos[n], neg[n];
        pos[0] = nums[0];
        neg[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pos[i] = max(pos[i-1] * nums[i], nums[i]);
            neg[i] = min(neg[i-1] * nums[i], nums[i]);
            
            pos[i] = max(neg[i-1] * nums[i], pos[i]);
            
            neg[i] = min(pos[i-1] * nums[i], neg[i]);
        }
        int mx = 0 - 0x7fffffff;
        for(int i = 0; i < n; i++) {
            mx = max( mx, max(pos[i], neg[i]) );
        }
        return mx;
    }
};
