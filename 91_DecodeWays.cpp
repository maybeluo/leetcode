// L25 need to think carefully.

class Solution {
public:

    // judge if 'ab'(eg. '12') is between 1 and 26.
    bool isBetween1To26(char a, char b) {
        if( a == '1' || ( a == '2' && ( b >= '0' && b <= '6' ) ) ) return true;
        return false;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        if(n < 1) return 0;
        
        vector<int> dp(n + 10, 0);
        
        dp[0] = 1;
        if(s[0] != '0')
            dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            if( s[i-1] != '0' ) {
                if( isBetween1To26(s[i-2], s[i-1]) ) {
                    dp[i] = dp[i-1] + dp[i-2];
                }
                else
                    dp[i] = dp[i-1];
            }
            else {
                if( isBetween1To26(s[i-2], s[i-1]) ) {
                    dp[i] = dp[i-2];
                }
                else
                    return 0;
            }
        }
        return dp[n];
    }
};
