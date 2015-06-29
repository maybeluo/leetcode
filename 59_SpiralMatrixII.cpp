// RE 1 times.
// If using the way in L24 to initialize two dimension vector (i.e. initialize with capacity), we should use L29 instead of L30.
// Similarly, if initializing the vector as the way in L25, use L30 to add new element.

class Solution {
public:
    void putCircle(vector<vector<int>>& matrix, int& pos, int x0, int y0, int x1, int y1) {
        for(int i = y0; i < y1; i++) { // up
            matrix[x0][i] = pos++;
        }
        for(int i = x0; i < x1; i++) { // right
            matrix[i][y1] = pos++;
        }
        for(int i = y1; i > y0; i--) { // bottom
            matrix[x1][i] = pos++;
        }
        for(int i = x1; i > x0; i--) { // left
            matrix[i][y0] = pos++;
        }
        return ;
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector< vector<int> > matrix(n);
        //vector< vector<int> > matrix;
        //matrix.clear();
        for(int i = 0; i < n; i++){
            vector<int> vt(n, 0);
            matrix[i] = vt;
            // matrix.push_back(vt);
        }
        int pos = 1;
        for(int i = 0; i < n/2; i++) {
            putCircle(matrix, pos, i, i, n-1-i, n-1-i);
        }
        if(n%2) matrix[n/2][n/2] = pos;
        return matrix;
    }
};
