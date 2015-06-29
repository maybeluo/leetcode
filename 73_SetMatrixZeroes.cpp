// WA many times: "i!= c" in L31 and "i!= r" in L39 

class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m < 1) return ;
        int n = matrix[0].size();
        if(n < 1) return;
        
        int r = -1, c = -1;
        for(int i = 0; i < m; i++){
            if(i == r) continue;
            for(int j = 0; j < n; j++){
                if( j == c) continue;
                if( matrix[i][j] == 0  ) {
                    if(r < 0){// first row and column used to store the index
                        r = i;
                        c = j;
                    }
                    matrix[r][j] = 0;//column index to be setted to 0
                    matrix[i][c] = 0;//row index to be setted to 0
                }
            }
        }
        
        if(r < 0 || c < 0) return;
        
        for(int i = 0; i < n; i++){
            if(i!= c && matrix[r][i] == 0){
                for(int j = 0; j < m; j++){
                    if(j != r) 
                        matrix[j][i] = 0;
                }
            }
        }
        for(int i = 0; i < m; i++){
            if(i!= r && matrix[i][c] == 0){
                for(int j = 0; j < n; j++){
                    if(j != c)
                        matrix[i][j] = 0;
                }
            }
        }
        
        for(int i = 0; i < m; i++) matrix[i][c] = 0;
        for(int i = 0; i < n; i++) matrix[r][i] = 0;
        
        return ;
    }
};



// the solution below can pass the judge. but there is a bug. we must choose a value which doesn't appear in matrix...
class Solution {
public:
    const int maxNeg = 0 - 0x5fffffff;
    void setNegative(vector<vector<int>>& matrix, int r, int c) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < n; i++) {
            if(matrix[r][i] != 0)
                matrix[r][i] = maxNeg;
        }
        for(int i = 0; i < m; i++){
            if(matrix[i][c] != 0)
                matrix[i][c] = maxNeg;
        }
        return ;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m < 1) return ;
        int n = matrix[0].size();
        if(n < 1) return;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if( matrix[i][j] == 0 ) setNegative(matrix, i, j);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if( matrix[i][j] == maxNeg ) matrix[i][j] = 0;
            }
        }
        
        return ;
    }
};
