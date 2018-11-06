// WA 1 times: take the input matrix as a sequare one.

// Figure 1.
// (x0, y0) ----------------------------------------(x0, y1)
//          | \                            \        |
//          |   \                            \      |
//          |     \ (m/2,m/2)    (m/2,n-1-m/2) \    |
//          |       \                            \  |
//          |         \                           \ |
// (x1, y0) ----------------------------------------(x1, y1)

class Solution {
public:
    // see figure 1, read the outermost layer of (x0, y0) to (x1, y1)
    void readCircle(vector<vector<int>>& matrix, vector<int>& ans, int x0, int y0, int x1, int y1) {
        for(int i = y0; i < y1; i++) { // up
            ans.push_back( matrix[x0][i] );
        }
        for(int i = x0; i < x1; i++) { // right
            ans.push_back( matrix[i][y1] );
        }
        for(int i = y1; i > y0; i--) { // bottom
            ans.push_back( matrix[x1][i] );
        }
        for(int i = x1; i > x0; i--) { // left
            ans.push_back( matrix[i][y0] );
        }
        return ;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        ans.clear();
        int m = matrix.size();
        if( m < 1 ) return ans;
        int n = matrix[0].size();
        
        int c = min(m/2, n/2);
        for(int i = 0; i < c; i++) {
            readCircle(matrix, ans, i, i, m-1-i, n-1-i);
        }
        if( m%2 && m <= n ) { // see figure 1
            for(int i = m/2; i <= n-1-m/2; i++)
                ans.push_back( matrix[m/2][i] );
        }
        if( n%2 && m > n ) {
            for(int i = n/2; i <= m-1-n/2; i++)
                ans.push_back( matrix[i][n/2] );
        }
        return ans;
    }
};
