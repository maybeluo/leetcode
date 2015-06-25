// fix one dimension, enumerate the other two as 2-sum problems.
// record the minminal value when enumerate.

class Solution {
public:
    typedef long long LL;
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        LL sep = 0x7fffffff, val = target;
        for(int i = 0; i < n; i++){
            int l = i + 1, r = n - 1;
            while( l < r ){
                LL t = nums[i] + nums[l] + nums[r];
                if( t == target ){
                    return target;
                }
                if( t > target ){
                    if( abs(t - target) < sep ){
                        val = t;
                        sep = abs(t - target);
                    }
                    r --;
                }
                else{
                    if( abs(t - target) < sep ){
                        val = t;
                        sep = abs(t - target);
                    }
                    l ++;
                }
            }
        }
        return val;
    }
};
