class Solution {
public:
    bool binarySearch(vector<int>& nums, int target, int a, int b) {
    	int l = a - 1, r = b + 1;
    	while( r - l > 1 ) {
    		int mid = (r + l ) >> 1;
    		if(nums[mid] >= target) r = mid;
    		else l = mid;
    	}
    	if(r > b || nums[r] != target) return false;
    	else return true;
    }
    bool search(vector<int>& nums, int target) {
    	int n = nums.size();
    	if(n < 1) return -1;
    
    	int l = 0, r = n - 1, m = 0;
    	while( l < r ) {
    	    while(l + 1 < r && nums[l] == nums[l+1]) l ++;
    	    while(r - 1 > l && nums[r-1] == nums[r]) r --;
    		int mid = (l + r) >> 1;
    		if(nums[mid] >= nums[0]) l = mid + 1;
    		else r = mid;
    	}
    	if(target >= nums[0]) { // left part
    		return binarySearch(nums, target, 0, r);
    	}
    	else { // right part
    		return binarySearch(nums, target, r, n-1);
    	}
    }
};
