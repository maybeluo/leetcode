// Two properties about XOR: 1) x^x = 0     2) 0^x = x

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        assert(n > 0);
        
        int ans = nums[0];
        for(int i = 1; i < n; i++) {
            ans ^= nums[i];
        }
        
        return ans;
    }
};
