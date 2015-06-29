// (i, j) -> (j, n-i-1) -> (n-i-1, n-j-1) -> (n-j-1, i)  [-> (i,j)] , every rotate process 4 points. 
// Thus only need to traverse n*n/4 points to rotate the matrix.
// The region to traverse is the above regeion of
//  the intersection of main diagonal and antidiagonal. (points on main diagonal are included, but not antidiagonal)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if( n < 1) return ;
        int c = n/2;
        if(n%2) c ++;
        for(int i = 0; i < c; i++){
            for(int j = i; j < n-i-1; j++ ) {
                swap( matrix[i][j], matrix[j][n-i-1] );
                swap( matrix[i][j], matrix[n-i-1][n-j-1] );
                swap( matrix[i][j], matrix[n-j-1][i] );
            }
        }
        return ;
    }
};
