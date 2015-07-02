// Bitwise iterate the 32-bit of each element in the array, get the median of each bit. Aggregate them together is the final result.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int num_zero = 0;
            int num_ones = 0;
            for(int j = 0; j < nums.size(); j++) {
                if( (nums[j] >> i) & 1 ) num_ones ++;
                else num_zero ++;
            }
            if(num_zero < num_ones) ans += (1 << i);
        }
        return ans;
    }
};
