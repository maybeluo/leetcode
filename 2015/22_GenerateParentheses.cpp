// WA many times: use Reference(&) in L6 !!!
//  Depth First Search

class Solution {
public:
    void dfs(vector<string>& vs, string ans, int n, int nl, int nr){
        if( nl==n && nr == n ){
            vs.push_back(ans);
            return ;
        }
        if(nl > nr ){
            if(nl < n) dfs( vs, ans + '(', n, nl + 1, nr );
            dfs( vs, ans + ')', n, nl, nr + 1 );
        }
        else if( nl == nr ){
            if(nl < n) dfs( vs, ans + '(', n, nl + 1, nr );
        }

    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        vs.clear();
        dfs(vs, "", n, 0, 0);
        return vs;
    }
};
