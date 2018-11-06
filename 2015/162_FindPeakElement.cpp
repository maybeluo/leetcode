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

// version 2
class Solution {
public:
    int dc(vector<int>& A, int l, int r) {
        if(l > r) return -1;
        int mid = (l + r) >> 1;
        int left = (mid - 1 >= 0) ? A[mid-1] : INT_MIN;
        int right = (mid + 1) < A.size() ? A[mid + 1] : INT_MIN;
        if(A[mid] > left && A[mid] > right) return mid;
        else if(A[mid] > left) return dc(A, mid + 1, r);
        else return dc(A, l, mid - 1);
    }
    
    int findPeak(vector<int> A) {
        return dc(A, 0, A.size() - 1);
    }
};
