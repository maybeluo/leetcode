// WA 2 times: 
//  1) misunderstanding the problem
//  2) L16: (t + '0'), NOT (t - '0')
// TLE 1 times: forget L43
// MLE 1 times: forget L17

class Solution {
public:
    typedef int LL;
    
    string intToString( LL n ){
        string s = "";
        if(n == 0) return "0";
        while( n > 0 ){
            LL t = n % 10;
            s += (t + '0');
            n /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    
    string getStr( string s) {
        LL nt = 0;
        string ans = "";
        for(int i = 0; i < s.size(); i++ ){
            if( i + 1 < s.size() && s[i] == s[i+1] ) nt ++;
            else{
                nt ++;
                ans += ( intToString(nt) + s[i] );
                nt = 0;
            }
        }
        return ans;
    }
    
    string countAndSay(int n) {
        assert( n >= 0);
        int cnt = 1;
        string pre = "1";
        while(cnt < n){
            pre = getStr(pre);
            cnt += 1;
        }
        
        return pre;
    }
};
