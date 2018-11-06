class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> v;
        v.clear();
        
        for(int k = 0; k < tokens.size(); k++) {
            string s = tokens[k];
            if( (s=="+" || s=="-") || (s=="*" || s=="/") ) { // an operator
                if( v.size() < 2 ) return -1; // ensure more than 2 elements
                int b = v.back();
                v.pop_back();
                int a = v.back();
                v.pop_back();
                if( s=="+" )  v.push_back(a+b);
                else if( s=="-" ) v.push_back(a-b);
                else if( s=="*" ) v.push_back(a*b);
                else if( s=="/" ) {
                    if(b == 0) return (0 - 0x7fffffff);
                    v.push_back(a/b);
                }
            }
            else {
                int i = 0, cnt = 0, flag = 0, n = s.size();
                while(s[i] == ' ' && i < n) i ++; // remove leading space
                if(i < n && s[i] == '-') { // negative number
                    flag = 1;
                    i ++;
                }
                else if(i < n && s[i] == '+') {
                    i ++;
                }
                while(i < n && s[i] == ' ') i ++; // remove space
                for(int j = i; j < n; j++) {
                    cnt = cnt * 10 + (s[j] - '0');
                }
                if(flag) cnt = 0 - cnt;
                v.push_back(cnt);
            }
        }
        
        return v.back();
        
    }
};
