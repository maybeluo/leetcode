// Breadth First Search

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

    void bfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
    	vector<Node> v;
    	v.clear();
    	Node cur(x, y);
    	v.push_back(cur);
    	while( !v.empty() ) {
    		cur = v.back();
    		v.pop_back();
    		grid[cur.x][cur.y] = '0';
    		for(int i = 0; i < 4; i++) {
    			int tx = cur.x + dirx[i], ty = cur.y + diry[i];
    			if( ( (tx >= 0 && tx < m) && (ty >= 0 && ty <= n) ) && grid[tx][ty] == '1' ) {
    				Node nt(tx,ty);
    				v.push_back(nt);
    			}
    		}
    	}
    }
    
    int numIslands(vector<vector<char>>& grid) {
    	int m = grid.size();
    	if(m < 1) return 0;
    	int n = grid[0].size();
    	
    	int ans = 0;
    	for(int i = 0; i < m; i++) {
    		for(int j = 0; j < n; j ++) {
    			if(grid[i][j] == '1') {
    				ans ++;
    				bfs(grid, i, j, m, n);
    			}
    		}
    	}
    	return ans;
    }
};
