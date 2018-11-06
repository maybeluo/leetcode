// TLE many times. After finding some solutions on the internet, I figured out that: L11 is essential!

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int p = i;
            while( p >= 0 ) {
                if( ( nums[p] <= 0 || nums[p] > n ) || nums[p] == p + 1 ) break;
                if( nums[p] == nums[ nums[p] -1 ] ) break;
                swap( nums[p], nums[ nums[p] -1 ] );
                //p = nums[p] - 1;
            }
        }
        int ans = 0;
        for(; ans < n; ans++){
            if( nums[ans] <= 0 || ans + 1 != nums[ans]) break;
        }
        return ans + 1;
    }
};

// Same trap, wrong again line version 1 in L11.
// L32 for avoiding swap same numbers again and again..
class Solution {
public:
    int firstMissingPositive(vector<int> A) {
        int n = A.size(), i = 0, j = 0;
        while(i < n) {
            if( (A[i] > 0 && A[i] <= n) 
             && ( A[i] - 1 != i && A[i] != A[ A[i] - 1 ] ) ) {
                swap( A[i], A[ A[i] - 1 ] );
            }
            else i ++;
        }
        for(i = 0; i < n; i++){
            if(A[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
