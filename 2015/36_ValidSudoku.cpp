// WA 1 times:
//  L37-38: shoud be "[x + i][y + j]", NOT "[i][j]"

class Solution {
public:
    bool isValidRow(vector<vector<char>>& board, int row){
        int flag[10];
        memset(flag, 0, 10*sizeof(int));
        for(int i = 0; i < 9; i++){
            if( board[row][i] != '.' ){
                int t = board[row][i] - '0';
                if(flag[t]) return false;
                else flag[t] = 1;
            }
        }
        return true;
    }
    
    bool isValidColumn(vector<vector<char>>& board, int col){
        int flag[10];
        memset(flag, 0, 10*sizeof(int));
        for(int i = 0; i < 9; i++){
            if( board[i][col] != '.' ){
                int t = board[i][col] - '0';
                if(flag[t]) return false;
                else flag[t] = 1;
            }
        }
        return true;
    }
    
    bool isValidSubMatrix(vector<vector<char>>& board, int x, int y){
        int flag[10];
        memset(flag, 0, 10*sizeof(int));
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if( board[x + i][y + j] != '.' ){
                    int t = board[x + i][y + j] - '0';
                    if(flag[t]) return false;
                    else flag[t] = 1;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            if( !isValidRow(board, i) ) return false;
        }
        for(int i = 0; i < 9; i++){
            if( !isValidColumn(board, i) ) return false;
        }
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                if( !isValidSubMatrix(board, i, j) ) return false;
            }
        }
        return true;
    }
};
