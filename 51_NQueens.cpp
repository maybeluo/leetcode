// Depth First Search. Fix row(or column), then enumerate column(or row).
// WA 2 times:
//  1) L41: ">= n - 1", NOT ">= n"
//  2) L35: diagonal attacks.

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
    
    void initQueenMatrix(vector<string>& ans, int n){
        for(int i = 0; i < n; i++) {
            string s = "";
            for(int j = 0; j < n; j++) s += '.';
            ans.push_back(s);
        }
        return ;
    }
    
    bool isValid(vector<Node> v, int x, int y) {
        for(vector<Node>::iterator it = v.begin(); it != v.end(); it ++) {
            Node nt = *it;
            if( x == nt.x || y == nt.y ) return false;
            if( abs(x - nt.x) == abs(y - nt.y) ) return false;
        }
        return true;
    }
    
    void dfs(vector< vector<Node> > & vv, vector<Node>& v, int n, int x) {
        if(x >= n - 1 ) {
            for(int i = 0; i < n; i++) {
                if( isValid(v, x, i) ) {
                    vector<Node> vt(v);
                    Node nt(x, i);
                    vt.push_back(nt);
                    vv.push_back(vt);
                }
            }
            return ;
        }
        for(int i = 0; i < n; i++) {
            if( isValid(v, x, i) ) {
                Node nt(x, i);
                v.push_back(nt);
                dfs(vv, v, n, x + 1);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector< vector<string> > ans;
        ans.clear();
        if( n < 1 ) return ans;
        
        vector< vector<Node> > vv;
        vv.clear();
        vector<Node> v;
        dfs(vv, v, n, 0);
        
        for(vector< vector<Node> >::iterator it = vv.begin(); it != vv.end(); it++ ) {
            vector<Node> vt(*it);
            vector<string> vs;
            vs.clear();
            initQueenMatrix(vs, n);
            for(vector<Node>::iterator jt = vt.begin(); jt != vt.end(); jt ++){
                Node nt = *jt;
                vs[nt.x][nt.y] = 'Q';
            }
            ans.push_back(vs);
        }
        return ans;
    }
};
