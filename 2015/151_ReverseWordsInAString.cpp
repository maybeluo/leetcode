// three pass, in-place
// TLE: L21, 'i = k', not 'i = 0'
// WA: L59, rembember to remove tail space

class Solution {
public:
    void reverseRange(string& s, int l, int r) {
        while(l < r) {
            swap(s[l], s[r]);
            l ++;
            r --;
        }
        return ;
    }
    
    void reverseWords(string &s) {
        int i = 0, j = 0, k = 0, n = s.size();
        
        // reverse every word in-place
        while(k < n) {
            for(i = k; i < n; i++) {
                if( s[i] != ' ' ) break;
            }
            for(j = i; j < n; j++) {
                if( s[j] == ' ' ) break;
            }
            reverseRange(s, i, j - 1);
            k = j + 1;
        }
        // cout<<s<<endl;
        
        // reverse the whole string
        reverseRange(s, 0, n-1);
        
        // remove unnecessary space
        int flag = 0;
        i = 0, k = 0;
        
        while(k < n && s[k] == ' ') {// leading space
            k ++;
        }
        
        while(k < n) {
            if(s[k] != ' ') {
                s[i] = s[k];
                i ++;
                flag = 0;
            }
            
            if(s[k] == ' ' && !flag ) { // first occurrence of space
                s[i] = s[k];
                i ++;
                flag = 1;
            }
            
            k ++;
        }
        
        if(s[i-1] == ' ') i --;// tail space
        
        s = s.substr(0, i);
    }
};
