// Dynamic Programming on string.

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.size() < 1) return false;
        
        int n = s.size();
        vector<int> dp(n, 0); // dp[i]: whether string from 0 to i can get valid break
        
        for(int i = 0; i < n; i++) {
            if( wordDict.find( s.substr(0, i + 1) ) != wordDict.end()  ) {
                dp[i] = 1;
            }
            else {
                for(int j = i - 1; j >= 0; j--) {
                    if(dp[j] && wordDict.find( s.substr(j + 1,i - j) ) != wordDict.end() ) {
                        dp[i] = 1; 
                        break; // only need to find a valid solution
                    }
                }
            }
        }
        if(dp[n-1]) return true;
        else return false;
    }
};
