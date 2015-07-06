// Divide and conquer

class Solution {
public:
    int dc(vector<int>& nums, int l, int r) {
        int mid = (l + r)/2;
        if( (mid == 0 || nums[mid] > nums[mid - 1]) 
            && (mid + 1 == nums.size() || nums[mid] > nums[mid + 1]) ) {
                return mid;
        }
        else if(mid + 1 < nums.size() && nums[mid + 1] > nums[mid]) {
            return dc(nums, mid + 1, r);
        }
        else {
            return dc(nums, l, mid - 1);
        }  
    }
    
    int findPeakElement(vector<int>& nums) {
        return dc(nums, 0, nums.size() - 1);
    }
};
