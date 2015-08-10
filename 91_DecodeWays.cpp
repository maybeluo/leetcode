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

// another version.
// three conditions when add s[i]:
//  1. s[i] can only exist independly    ==>    dp[i] = dp[i-1]
//  2. s[i] can exist independly and can merge with s[i-1]    ==>    dp[i] = dp[i-1] + dp[i-2]
//  3. s[i] can only exist bound with s[i-1]    ==>   dp[i] = dp[i-2]
// 1&2 can write some conditions together.
int numDecodings(string s) {
	int n = s.size();
	if(n < 1 || s[0] == '0') return 0;
	vector<int> dp(n+1, 0);
	dp[0] = 1;
	for(int i = 1; i < n; i++) {
		if( s[i] >= '1' && s[i] <= '9' ) { // can exist independly
			dp[i] = dp[i-1];
		}
		if( (s[i-1] == '1' && ( s[i] >= '1' && s[i] <= '9' ) )
			|| (s[i-1] == '2' && ( s[i] >= '1' && s[i] <= '6' ) ) ) {
					dp[i] += ( (i > 1) ? dp[i-2] : 1);
		}
		if( s[i] == '0' && ( s[i-1] == '1' || s[i-1] == '2' ) ) { // can only bound with s[i-1]
			dp[i] = (i > 1) ? dp[i-2] : 1;
		}
	}
	return dp[n-1];
}
