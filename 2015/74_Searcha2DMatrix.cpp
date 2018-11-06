class Solution {
public:
    bool dc(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, int target) {
        if(x1 > x2 || y1 > y2) return false;
        int midx = (x1 + x2) >> 1, midy = (y1 + y2) >> 1;
        if( matrix[midx][midy] == target ) return true;
        else if( matrix[midx][midy] < target ) {
            return dc(matrix, midx, midy + 1, x2, y2, target) || dc(matrix, midx + 1, y1, x2, midy, target);
        }
        else {
            return dc(matrix, x1, y1, midx, midy - 1, target) || dc(matrix, x1, midy, midx - 1, y2, target);
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m < 1) return false;
        
        int n = matrix[0].size();
        return dc(matrix, 0, 0, m - 1, n - 1, target);
    }
};
