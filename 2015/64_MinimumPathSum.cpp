//Dynamic Programming: can move only to right or down makes this problem easy.
//  dp[i][j] : minimum sum of paths to get point (i,j)
//  dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int nrow = grid.size();
        if(nrow < 1) return 0;
        
        int ncol = grid[0].size();
        if(ncol < 1) return 0;
        
        int dp[nrow + 10][ncol + 10];
        memset(dp, 0, (nrow + 10)*(ncol + 10)*sizeof(int));
        int t_sum = 0;
        for(int i = 0; i < nrow; i++) {
            t_sum += grid[i][0];
            dp[i][0] = t_sum;
        }
        t_sum = 0;
        for(int i = 0; i < ncol; i++) {
            t_sum += grid[0][i];
            dp[0][i] = t_sum;
        }
        
        for(int i = 1; i < nrow; i ++){
            for(int j = 1; j < ncol; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[nrow - 1][ncol - 1];
    }
};
