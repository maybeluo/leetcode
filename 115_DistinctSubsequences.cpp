// dp[i+1][j+1]: number of distinct sequences in s[0,i] and t[0,j].
// dp[i+1][j+1] = dp[i][j + 1] + (s[i] == t[j] ? dp[i][j]: 0)

// ver 1.
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if(m < 1 && n < 1) return 1; // both empty
        if(m < 1 && n >= 1) return 0;
        if(n < 1) return m;
        
        vector< vector<int> > dp(m + 1);
        for(int i = 0; i <= m; i++) {
            vector<int> v(n + 1, 0);
            dp[i] = v;
        }
        
        dp[0][0] = 1;
        for(int i = 0; i < m; i++) {
            dp[i+1][0] = dp[i][0];
            if(s[i] == t[0]) 
                dp[i+1][1] += 1;
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j ++) {
                dp[i + 1][j + 1] = dp[i][j + 1];
                if(s[i] == t[j]) {
                    dp[i + 1][j + 1] += dp[i][j];
                }
            }
        }
        return dp[m][n];
    }
};

// ver 2.
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if(m < 1 && n < 1) return 1; // both empty
        if(m < 1 && n >= 1) return 0;
        if(n < 1) return m;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < m; i++) {
            for(int j = n - 1; j >= 0; j --) {
                if(s[i] == t[j])
                    dp[j+1] += dp[j];
            }
        }
        return dp[n];
    }
};
