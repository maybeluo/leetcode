// Let the problem be a/b and suppose a > b > 0, then there must exists a integer k that satisfies: b*2^k <= a < b*2^(k+1).
// Why? From the inequality, we get log(a/b) - 1 < k <= log(a/b). Obviously there exists a integer in ( log(a/b) - 1, log(a/b) ].
// Use bit shifting to find k.

class Solution {
public:
    typedef long long LL;
    int divide(int dividend, int divisor) {
        const int MAX_INT = 2147483647;
        LL end = dividend, sor = divisor;
        int flag = 0;
        if( (end > 0 && sor < 0) || (end < 0 && sor > 0) ) flag = 1;
        if(end < 0) end = 0 - end;
        if(sor < 0) sor = 0 - sor;
        
        LL ans = 0, cnt = 0;
        while(end >= sor){
            cnt = 1;
            LL a = sor;
            while( a <= end ){
                a <<= 1;
                cnt <<= 1;
            }
            end -= (a >> 1);
            ans += (cnt >> 1);
        }
        
        if(flag) ans = 0 - ans;
        
        if(ans > MAX_INT) return MAX_INT;
        
        return ans;
    }
};
