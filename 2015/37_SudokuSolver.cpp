class Solution {
public:
    bool isValidRow(vector<vector<char>>& board, int row, char c){
        int flag[10];
        memset(flag, 0, 10*sizeof(int));
        flag[c - '0'] = 1;
        int n = board.size();
        for(int i = 0; i < n; i++){
            if( board[row][i] != '.' ){
                int t = board[row][i] - '0';
                if(flag[t]) return false;
                else flag[t] = 1;
            }
        }
        return true;
    }
    
    bool isValidColumn(vector<vector<char>>& board, int col, char c){
        int flag[10];
        memset(flag, 0, 10*sizeof(int));
        flag[c - '0'] = 1;
        int n = board.size();
        for(int i = 0; i < n; i++){
            if( board[i][col] != '.' ){
                int t = board[i][col] - '0';
                if(flag[t]) return false;
                else flag[t] = 1;
            }
        }
        return true;
    }
    
    bool isValidSubMatrix(vector<vector<char>>& board, int x, int y, char c){
        int flag[10];
        memset(flag, 0, 10*sizeof(int));
        flag[c - '0'] = 1;
        int bx = (x/3)*3, by = (y/3)*3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if( board[bx + i][by + j] != '.' ) {
                    int t = board[bx + i][by + j] - '0';
                    if(flag[t]) return false;
                    else flag[t] = 1;
                }
            }
        }
        return true;
    }
    
    bool isValidCurrentBoard(vector<vector<char>>& board, int x, int y, char c){
        if( !isValidRow(board, x, c) ) return false;
        if( !isValidColumn(board, y, c) ) return false;
        if( !isValidSubMatrix(board, x, y, c) ) return false;
        return true;
    }
    
    bool dfs(vector<vector<char>>& board, int n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.') {
                    for(int k = 1; k <= 9; k ++) {
                        char c = k + '0';
                        if( isValidCurrentBoard(board, i, j, c) ) {
                            board[i][j] = c;
                            if( ! dfs(board, n) ) board[i][j] = '.';
                            else return true;
                        }
                    }
                    return false; // try 1-9 but can't work
                }
            }
        }
        return true; // all is filled.
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        if(n < 1) return ;
        dfs(board, n);
        return ;
    }
};
