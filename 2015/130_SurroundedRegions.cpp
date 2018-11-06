// RTE when useing DFS.
// BFS
// WA: L27 is necessary.

typedef struct node {
	int x, y;
	node() {}
	node(int _x, int _y) {
		x = _x;
		y = _y;
	}
} Node; 

int dirx[4] = {0,1,0,-1};
int diry[4] = {-1,0,1,0};

class Solution {
public:
    void mergeVector(vector<Node>& ret, vector<Node>& v) {
    	for(vector<Node>::iterator it = v.begin(); it != v.end(); it++) {
    		ret.push_back(*it);
    	}
    }
    
    vector<Node> bfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
    	int flag = 0;
    	if( (x == 0 || x == m -1) || (y == 0 || y == n - 1) ) flag = 1;
    	vector<Node> v, ans;
    	v.clear();
    	ans.clear();
    	Node cur(x, y);
    	v.push_back(cur);
    	while( !v.empty() ) {
    		cur = v.back();
    		v.pop_back();
    		ans.push_back(cur);
    		grid[cur.x][cur.y] = 'X';
    		for(int i = 0; i < 4; i++) {
    			int tx = cur.x + dirx[i], ty = cur.y + diry[i];
    			if( ( (tx >= 0 && tx < m) && (ty >= 0 && ty <= n) ) && grid[tx][ty] == 'O' ) {
    				if( (tx == 0 || tx == m -1) ||(ty == 0 || ty == n - 1) ) flag = 1;
    				Node nt(tx,ty);
    				v.push_back(nt);
    			}
    		}
    	}
    	if( !flag ) ans.clear();
    	return ans;
    }
    
    void solve(vector<vector<char>>& board) {
    	int m = board.size();
    	if(m < 1) return ;
    	int n = board[0].size();
    	
    	vector<Node> ret;
    	ret.clear();
    	for(int i = 0; i < m; i++) {
    		for(int j = 0; j < n; j ++) {
    			if(board[i][j] == 'O') {
    				vector<Node> tmp = bfs(board, i, j, m, n);
    				if( !tmp.empty() ) {
    					mergeVector(ret, tmp);
    				}
    			}
    		}
    	}
    	for(vector<Node>::iterator it = ret.begin(); it != ret.end(); it++) {
    		Node nt = *it;
    		board[nt.x][nt.y] = 'O';
    	}
    	return ;
    }
};
