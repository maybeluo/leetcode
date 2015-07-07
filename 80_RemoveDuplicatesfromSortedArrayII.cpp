// RTE 1 time: L10 is "i=j", not "i++"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        
        int i = 0, j = 0, pos = 0;
        for(i = 0; i < n; i = j) {
            for(j = i + 1; j < n; j++) {
                if(nums[i] != nums[j] ) break;
            }
            int p = min(2, j - i);
            for(int k = 0; k < p; k ++) {
                nums[pos] = nums[i + k];
                pos ++;
            }
        }
        return pos;
    }
};
