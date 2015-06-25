//Dynamic Programming: can move only to right or down makes this problem easy.
//  dp[i][j] : number of unique paths to get point (i,j)
//  dp[i][j] = dp[i-1][j] + dp[i][j-1]

class Solution {
public:
    int uniquePaths(int m, int n) {
        if( m < 1 || n < 1 ) return 0;
        int dp[m+10][n+10];
        memset(dp, 0, (m+10)*(n+10)*sizeof(int));
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int j = 0; j < n; j++) dp[0][j] = 1;
        for(int i = 1; i < m; i ++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
