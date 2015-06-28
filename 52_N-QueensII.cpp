// See P51.

class Solution {
public:
    class Node{
    public:
        int x;
        int y;
        Node() {
            x = -1;
            y = -1;
        }
        Node(int t_x, int t_y) {
            x = t_x;
            y = t_y;
        }
    };

    bool isValid(vector<Node> v, int x, int y) {
        for(vector<Node>::iterator it = v.begin(); it != v.end(); it ++) {
            Node nt = *it;
            if( x == nt.x || y == nt.y ) return false;
            if( abs(x - nt.x) == abs(y - nt.y) ) return false;
        }
        return true;
    }
    
    void dfs(vector<Node>& v, int n, int x, int& cnt) {
        if(x >= n - 1 ) {
            for(int i = 0; i < n; i++) {
                if( isValid(v, x, i) ) {
                    cnt += 1;
                }
            }
            return ;
        }
        for(int i = 0; i < n; i++) {
            if( isValid(v, x, i) ) {
                Node nt(x, i);
                v.push_back(nt);
                dfs(v, n, x + 1, cnt);
                v.pop_back();
            }
        }
    }
    
    int totalNQueens(int n) {

        if( n < 1 ) return n;
        int cnt = 0;
        vector<Node> v;
        dfs(v, n, 0, cnt);
        
        return cnt;
    }
    
};
