// a wonderful explanation of various binary search: http://blog.chinaunix.net/uid-1844931-id-3337784.html
// L13: pay close attention to it.

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if( n < 1 ) return 0;
        
        int l = 0, r = n - 1;
        while( l <= r ) {
            int mid = (l + r)/2;
            if( nums[mid] >= target ) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};
