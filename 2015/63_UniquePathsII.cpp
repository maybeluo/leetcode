// Dynamic Programming, see P62
// WA 1 times because of neglecting L20 and L26.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int nrow = obstacleGrid.size();
        if(nrow < 1) return 0;
        
        int ncol = obstacleGrid[0].size();
        if(ncol < 1) return 0;
        
        int dp[nrow + 10][ncol + 10];
        memset(dp, 0, (nrow + 10)*(ncol + 10)*sizeof(int));
        for(int i = 0; i < nrow; i++) {
            if( ! obstacleGrid[i][0] ){
                dp[i][0] = 1;
            }
            else break;
        }
        for(int i = 0; i < ncol; i++) {
            if( ! obstacleGrid[0][i] ){
                dp[0][i] = 1;
            }
            else break;
        }
        
        for(int i = 1; i < nrow; i ++){
            for(int j = 1; j < ncol; j++){
                if( ! obstacleGrid[i][j] ){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[nrow - 1][ncol - 1];
    }
};
