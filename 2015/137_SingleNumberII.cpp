// See solution here: http://www.acmerblog.com/leetcode-single-number-ii-5394.html
// A integer in computer is 32-bit of 0 and 1.
// If a number x appears k times, then we add the i-th bit of x by k times, the sum must be 0 or k. Both to be 0 mod k.
// Then the numbers which appear k times are removed by "bitwise" addition k times.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int bitSize = 32;
        int flag[bitSize];
        memset(flag, 0, bitSize*sizeof(int));
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < bitSize; j++) {
                if( (nums[i] >> j) & 1 ) // the j-th bit of nums[i] is 1
                    flag[j] ++;
            }
        }
        for(int j = 0; j < bitSize; j++) {
            ans |= ( (flag[j]%3) << j );
        }
        return ans;
    }
};
