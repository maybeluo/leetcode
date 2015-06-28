// TLE many times. After finding some solutions on the internet, I figured out that: L11 is essential!

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int p = i;
            while( p >= 0 ) {
                if( ( nums[p] <= 0 || nums[p] > n ) || nums[p] == p + 1 ) break;
                if( nums[p] == nums[ nums[p] -1 ] ) break;
                swap( nums[p], nums[ nums[p] -1 ] );
                //p = nums[p] - 1;
            }
        }
        int ans = 0;
        for(; ans < n; ans++){
            if( nums[ans] <= 0 || ans + 1 != nums[ans]) break;
        }
        return ans + 1;
    }
};
