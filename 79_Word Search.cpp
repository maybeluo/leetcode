class Solution {
public:
    int dirx[4] = {-1, 0, 1, 0};
    int diry[4] = {0, -1, 0, 1};
    
    bool dfs(vector<vector<char>>& board, string word, int dep, int r, int c) {
        if(dep > word.size()) return false;
        if(dep == word.size()) return true;
        for(int i = 0; i < 4; i++) {
            int x = r + dirx[i], y = c + diry[i];
            if( (x >= 0 && x < board.size()) && (y >= 0 && y < board[0].size()) ) {
                if( board[x][y] != '.' && board[x][y] == word[dep] ) {
                    char t = board[x][y];
                    board[x][y] = '.';
                    if( dfs(board, word, dep + 1, x, y) )
                        return true;
                    else
                        board[x][y] = t;
                }
            }
        }
        return false;
    }
        
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() < 1) return true;
        if(board.size() < 1) return false;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if( board[i][j] == word[0] ) {
                    board[i][j] = '.';
                    if( dfs(board, word, 1, i, j) ) return true;
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};
