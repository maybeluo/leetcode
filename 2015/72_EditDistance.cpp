// Need to modify: using rolling array instead of n1*n2
// WA 1 times: L23. make the state transition clear.

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int dp[n1 + 10][n2 + 10];
        memset(dp, 0, (n1 + 10)*(n2 + 10)*sizeof(int));
        for(int i = 0; i <= n1; i++) dp[i][0] = i;
        for(int j = 0; j <= n2; j++) dp[0][j] = j;
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++) {
                dp[i][j] = 0x5fffffff;
            }
        }
        word1.insert(0, " ");
        word2.insert(0, " ");
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++) {
                if( word1[i] == word2[j] ) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                    //dp[i][j] = min( dp[i][j], min(dp[i-1][j], dp[i][j-1]) );
                }
                else{
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
                    dp[i][j] = min( dp[i][j], min(dp[i-1][j] + 1, dp[i][j-1] + 1) );
                }
            }
        }
        return dp[n1][n2];
    }
};
