class Solution {
public:
    
    // All the elements in A aren't smaller than B
    bool isContains(vector<int>& A, vector<int>& B) {
        for(int i = 0; i < A.size(); i ++) {
            if(A[i] < B[i]) return false;
        }        
        return true;
    }
        
    string minWindow(string s, string t) {
        const int alphaNum = 256;
        vector<int> flag_t(alphaNum + 10, 0), flag_s(alphaNum + 10, 0);
        
        for(string::iterator it = t.begin(); it != t.end(); it++) {
            flag_t[*it] ++;
        }
        
        int fst = 0, a, b;
        int i = 0, j = 0, n = s.size(), dw = 0x5fffffff;
        
        // find minimum window
        int pos = j;
        while(i < n) {
            a = s[i], b = s[j];
            flag_s[a] ++;
            if(flag_t[a] > 0) {
                if( !fst && isContains(flag_s, flag_t) ) {
                    fst = 1; // first occurrence
                }
                if(fst) {
                  // try to reduce the window size
        					while( j <= i ) {
                    b = s[j];
                    if( flag_t[b] > 0 && (flag_s[b] - 1 < flag_t[b]) ) break;
                    flag_s[b] --;
                    j ++;
                	}
	                // smaller window is founded
	                if(dw > i - j + 1) {
		                pos = j;
		                dw = i - j + 1;
	            		}
                }
            }
            i ++;
        }
        
        if(!fst)
            return "";
        else
            return s.substr(pos, dw);
    }
};
