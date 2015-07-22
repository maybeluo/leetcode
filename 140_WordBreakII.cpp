// DP to judge validation
// Backtracking to find every path.
// TLE many times: L20, "i < dp.size()", not "<="

class Solution {
public:
    void findPath(vector<string>& v, vector< vector<int> > & dp, vector<int>& path, int pos, string s) {
        if(pos == 0) {
            int m = path.size();
            if(m >= 2) {
                string ans = "";
                ans += s.substr(0, path[m-2]);
                for(int k = m - 2; k > 0; k--) {
                    ans += (" " + s.substr(path[k], path[k-1] - path[k]) );
                }
                v.push_back(ans);
            }
            return ;
        }
        for(int i = 0; i < dp.size(); i++) {
            if( dp[i][pos] ) {
                path.push_back(i);
                findPath(v, dp, path, i, s);
                path.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<string> v;
        v.clear();
        
        if(n < 2) {
            if( n == 1 && wordDict.find(s) != wordDict.end() ) v.push_back(s);
            return v;
        }
        
        // vp[i][j]: a substring of s, "i ~ j-1". handle carefully.
        vector< vector<int> > vp(n + 1); // recode path
        for(int i = 0; i < n + 1; i++) {
            vector<int> vt(n + 1, 0);
            vp[i] = vt;
        }
        
        unordered_set<int> able; // can be divied into words in dictionary
        able.clear();
        for(int i = 0; i < n; i++) {
            int flag = 0;
            if( wordDict.find( s.substr(0, i + 1) ) != wordDict.end() ) {
                vp[0][i + 1] = 1;
                flag = 1;
            }
            
            for(unordered_set<int>::iterator it = able.begin(); it != able.end(); it ++) {
                if( wordDict.find( s.substr(*it, i + 1 - *it) ) != wordDict.end() ) {
                    vp[*it][i + 1] = 1;
                    flag = 1;
                }
            }
            if(flag) able.insert(i + 1);
        }
        if( able.find(n) == able.end() ) { // no valid split
            return v;
        }
        
        vector<int> path;
        path.clear();
        path.push_back(n);
        findPath(v, vp, path, n, s);
        
        return v;
        
    }
};
