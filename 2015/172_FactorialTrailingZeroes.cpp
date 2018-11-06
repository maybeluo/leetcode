// the number of factor 5.
// WA: 25 = 5^2 has two factor of 5.

class Solution {
public:
    int trailingZeroes(int n) {
        long long base = 5, ans = 0;
        while( n >= base ) {
            ans += n/base;
            base *= 5;
        }
        return ans;
    }
};
