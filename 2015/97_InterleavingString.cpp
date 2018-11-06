// use TWO array to record situations of: s3[0, k] ends with s1, and ends with s2. A common method for DP.
// initilization are tricky. L23-L26 must be putted in L21. Same for L31-L34.
// be careful with the index.

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	int m = s1.size(), n = s2.size();
    	if( m + n != s3.size() ) return false;
    	if(m < 1 && n < 1) return true;
    	
    	// vx: end with alphabet from s1
    	// vy: end with alphabet from s2
    	vector< vector<bool> > vx(m + 1), vy(m + 1);
    	for(int i = 0; i <= m; i++) {
    		vector<bool> v1(n + 1, false), v2(n + 1, false);
    		vx[i] = v1;
    		vy[i] = v2;
    	}
    	
    	if(s3[0] == s1[0])  {
    	    vx[1][0] = true;
    	    for(int i = 1; i < m; i++) {
        		if(s1[i] == s3[i] ) vx[i+1][0] = true;
        		else break;
        	}
    	}

    	if(s3[0] == s2[0]) {
    		vy[0][1] = true;
        	for(int i = 1; i < n; i++) {
        		if(s2[i] == s3[i] ) vy[0][i+1] = true;
        		else break;
        	}
    	}
    	
    	for(int i = 0; i < m; i++) {
    		for(int j = 0; j < n; j++) {
    			if(s3[i + j + 1] == s1[i]) {
    				vx[i + 1][j + 1] = ( vx[i][j + 1] || vy[i][j + 1] );
    			}
    			if(s3[i + j + 1] == s2[j]) {
    				vy[i + 1][j + 1] = ( vx[i + 1][j] || vy[i + 1][j] );
    			}
    		}
    	}
    	return (vx[m][n] || vy[m][n]);
    }
};
