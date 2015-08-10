// version 1. 
// L12 for initialization
bool isMatch(string s, string p) {
	int m = s.size(), n = p.size();
	vector< vector<bool> > dp(m + 1);
	for(int i = 0; i <= m; i++) {
		vector<bool> v(n+1, false);
		dp[i] = v;
	}
	
	dp[0][0] = true;
	for(int j = 1; j <= n; j++) dp[0][j] = ( dp[0][j-1] && (p[j-1] == '*') );
	
	for(int j = 0; j < n; j++) {
		if(p[j] == '*') {
			for(int i = 0; i < m; i++) dp[i + 1][j + 1] = (dp[i][j] || (dp[i+1][j] || dp[i][j+1]) );
		}
		else {
			for(int i = 0; i < m; i++) {
				if( s[i] == p[j] || p[j] == '?' ) dp[i + 1][j + 1] = dp[i][j];
			}
		}
	}
	
	return dp[m][n];
}

