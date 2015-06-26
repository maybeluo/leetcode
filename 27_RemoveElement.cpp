// Two pointers.
// WA 1 times: shold remove the given element out of the vector, see L18-L20

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if( n < 1 ) return 0;
        int l = 0, r = n - 1;
        while( l < n && nums[l] != val ) l ++;
        while( l < r ){
            if( nums[r] != val ) {
                nums[l] = nums[r];
                while( l < r && nums[l] != val ) l ++;
            }
            r --;
        }
        for(int i = 0; i < n - l; i++){
            nums.pop_back();
        }
        return l;
    }
};
