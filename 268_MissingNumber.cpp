class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, n = nums.size();
        while(i < n) {
            if( (nums[i] >= 0 && nums[i] < n) && (nums[i] != i && nums[nums[i]] != nums[i]) ) {
                swap(nums[i], nums[ nums[i] ]);
            }
            else i ++;
        }
        for(i = 0; i < n; i++) {
            if(nums[i] != i) return i;
        }
        return n;
    }
};
