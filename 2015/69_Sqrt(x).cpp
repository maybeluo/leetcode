// binary search

typedef long long LL;
class Solution {
public:
    int mySqrt(int x) {
        if(x < 0) return 0;
        LL y = x;
        LL l = 0, r = y + 1;
        while(l < r - 1) {
            LL mid = (l + r) >> 1;
            if(y - mid*mid < 0) r = mid;
            else l = mid;
        }
        return l; 
    }
};
