// L55 && L10.

class Solution {
public:
    void findPath(vector< vector<string> > & vv, vector< vector<int> > & dp, vector<int>& path, int pos, string& s) {
        if(pos < 0) {
            vector<string> v;
            v.clear();
            int m = path.size();
            if(m >= 2) {
                for(int k = m - 1; k > 0; k--) {
                    v.push_back( s.substr(path[k], path[k-1] - path[k]) );
                }
            }
            v.push_back( s.substr(path[0], s.size() - path[0]) ); // if m < 2, this is equal to put the whole s in.
            vv.push_back(v);
            return ;
        }
        for(int i = 0; i < dp.size(); i++) {
            if(dp[i][pos]) {
                path.push_back(i);
                findPath(vv, dp, path, i-1, s);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector< vector<string> > vv;
        vv.clear();
        
        int n = s.size();
        if(n < 1) return vv;
        
        vector< vector<int> > dp(n);
        for(int i = 0; i < n; i++) {
            vector<int> v(n, 0);
            dp[i] = v;
        }
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < n; j++ ) {
                if(i <= j && s[i] == s[j]) {
                	if( (i <= j - 2  && dp[i+1][j-1]) || (i > j- 2) ) {
                    	dp[i][j] = 1;
                	}
                }
            }
        }
        
        vector<int> path;
        path.clear();
        
        int pos = n-1;
        //path.push_back(n-1);
        findPath(vv, dp, path, pos, s);
        return vv;
    }
};


// Backtracking.
class Solution {
public:
    bool isPalindrome(string&s, int l, int r) {
        if(l > r) return false;
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    
    void findPath(vector< vector<string> > & vv, vector<string>& path, int pos, string& s) {
        if(pos == s.size()) {
            vv.push_back(path);
            return ;
        }
        for(int i = pos; i < s.size(); i++) {
            if( isPalindrome(s, pos, i) ) {
                path.push_back( s.substr(pos, i - pos + 1) );
                findPath(vv, path, i + 1, s);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector< vector<string> > vv;
        vv.clear();
        
        vector<string> path;
        path.clear();
        
        int pos = 0;
        findPath(vv, path, pos, s);
        return vv;
    }
};
