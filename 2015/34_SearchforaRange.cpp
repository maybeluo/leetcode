// Binary Search is one of those shadows since I participated in ICPC. Of course, there are many shadows...
// a wonderful explanation of various binary search: http://blog.chinaunix.net/uid-1844931-id-3337784.html
// STL in C++ has corresponding function: lower_bound and upper_bound.
// L15, L27: specific attention
// L18, L30: boundary conditions

class Solution {
public:

    int lowerBound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if( l > r ) return -1;
        while( l <= r ) {
            int mid = (l+r)/2;
            if( nums[mid] >= target ) r = mid - 1;
            else l = mid + 1;
        }
        if( l < nums.size() && nums[l] == target ) return l;
        return -1;
    }
    
    int upperBound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if( l > r ) return -1;
        while( l <= r ) {
            int mid = (l+r)/2;
            if( nums[mid] > target ) r = mid - 1;
            else l = mid + 1;
        }
        if( r >= 0 && nums[r] == target ) return r;
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> vt(2,-1);
        if( n < 1 ) return vt;
        int low = lowerBound(nums, target);
        if( low >= 0 ){
            vt[0] = low;
            vt[1] = upperBound(nums, target);
        }
        return vt;
    }
};
