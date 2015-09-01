class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int c = 0;
        for(int i = 0; i < nums.size(); i++) {
            c ^= nums[i];
        }
        
        int k = 0;
        for(int i = 0; i < 31; i++) {
            if( (c >> i) & 0x01 ) {
                k = i;
                break;
            }
        }
        
        vector<int> ans(2, 0);
        for(int i = 0; i < nums.size(); i++) {
            if( (nums[i] >> k) & 0x01 ) ans[0] ^= nums[i];
            else ans[1] ^= nums[i];
        }
        
        return ans;
    }
};
