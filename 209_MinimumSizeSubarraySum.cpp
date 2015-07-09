// L18 must before L19.

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int dw = 0x5fffffff; // window size
        int fst = 0, ans = 0;
        int i = 0, j = 0, cnt = 0;
        
        while(i < n) {
            cnt += nums[i];
            if( !fst && cnt >= s ) {
                fst = 1;
            }
            if(fst) {
                while( cnt - nums[j] >= s) {
                    cnt -= nums[j];
                    j ++;
                }
                if(dw > i - j + 1) {
                    dw = i - j + 1;
                    ans = cnt;
                }
            }
            i ++;
        }
        
        if(fst)
            return dw;
        else
            return 0;
            
    }
};
