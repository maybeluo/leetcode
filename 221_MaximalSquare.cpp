// WA 1 times because of ignoring L16.
// Dynamic Programming:
//  dp[i][j] :the max length of a square whose low-right corner is (i,j)
//  dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int nrow = matrix.size();
        if( nrow < 1 ) return 0;
        int ncol = matrix[0].size();
        if( ncol < 1 ) return 0;
        
        int mx = 0;
        int dp[nrow + 10][ncol + 10];
        memset(dp, 0, (nrow + 10)*(ncol + 10)*sizeof(int) );
        for(int i = 0; i < nrow; i++){
            for(int j = 0; j < ncol; j++){
                if(matrix[i][j] == '1') dp[i][j] = 1;
                mx = max( mx, dp[i][j] );
            }
        }
        
        for(int i = 1; i < nrow; i++){
            for(int j = 1; j < ncol; j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min( dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]) ) + 1;
                }
                mx = max( mx, dp[i][j] );
            }
        }
        return mx*mx;
    }
};
