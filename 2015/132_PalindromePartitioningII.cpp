// I got stuck into the problem for a whole day!!!

// Take care of the meaning of each array defined. L31 & L35, L48 & L52

// If define the "cut" array as the minmum cut for [0,i)
//   you must to the order of loop as the way in L27 and L28 (fix j first), and initilize the "cut" array in the way like L

// If define the "cut" array as the minmum cut for [i, n)
//   you must to the order of loop as the way in L44 and L45 (fix i first), and initilize the "cut" array in the way like L

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n < 2) return 0;
        
        vector<int> cut(n + 1, 0);
        vector< vector<int> > dp(n);
        /*
        for(int i = 0; i < n; i++) {
            vector<int> v(n, 0);
            dp[i] = v;
            cut[i] = i - 1; // minimum cut for [0, i)
        }
        cut[n] = n - 1;
        
        for(int j = 0; j < n; j++) {
        	for(int i = j; i >= 0; i--) {
                if( (s[i] == s[j]) && ( j - i < 2  || dp[i+1][j-1] ) ) {
                    dp[i][j] = 1;
                    cut[j + 1] = min(cut[j + 1], cut[i] + 1);
                }
            }
        }
        return cut[n];
        */
        for(int i = 0; i < n; i++) {
            vector<int> v(n, 0);
            dp[i] = v;
            cut[i] = n - i - 1; //minimum cut for [i, n-1]
        }
        cut[n] = -1;
        
        for(int i = n - 1; i >= 0; i--) {
    	    for(int j = i; j < n; j++ ) {
                if( (s[i] == s[j]) && ( j - i < 2  || dp[i+1][j-1] ) ) {
                    dp[i][j] = 1;
                    cut[i] = min(cut[i], cut[j+1] + 1);
                }
            }
        }
        return cut[0];
    }
};
