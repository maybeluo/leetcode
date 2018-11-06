// Reverse two times: [a0,a1,...,a(n-k),...,a(n-1)] -> [a(n-1),...,a(n-k),...,a0] -> [a(n-k),...,an,  a0,...,a(n-k-1)]

class Solution {
public:
    void reverseByRange(vector<int>& nums, int l, int r){
        while(l < r){
            swap(nums[l], nums[r]);
            l ++;
            r --;
        }
        return ;
    }
    
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if( n < 1 ) return ;
        k = k%n;
        if(k < 1) return ;
        reverseByRange(nums, 0, n - 1);
        reverseByRange(nums, 0, k - 1);
        reverseByRange(nums, k, n - 1);
        return;
    }
};
