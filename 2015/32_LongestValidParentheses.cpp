// Bracket Matching problem, use the idea of Stack.
// Sense of greedy...
// WA 2 times:
//    1) ignore the matching must be continuous.
//    2) ignore the situation when the input string is a perfect bracket matching
class Solution {
    public:
        class myNode{
        private:
            char c;
            int pos;
    
        public:
            myNode();
            myNode( char t_c, int t_pos ){
                c = t_c;
                pos = t_pos;
            }
            char getC(){
                return c;
            }
            int getPos(){
                return pos;
            }
    };
    
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n < 2) return 0;
        vector<myNode> vt;
        for(int i = 0; i < n; i++){
            if( s[i] == '(' ) vt.push_back( myNode(s[i], i) );
            if( s[i] == ')'){
                 if( vt.size() > 0 && vt.back().getC() == '(' ) {
                    vt.pop_back();
                }
                else{
                    vt.push_back( myNode(s[i], i) );
                }
            }
        }
        int ans = 0;
        int nl = vt.size();
        if(nl < 1) return n;
        if(nl > 0){
            ans = max(ans, vt[0].getPos() );
            ans = max(ans, n - 1 - vt[nl-1].getPos() );
        }
        for(int i = 1; i < nl; i++){
            ans = max(ans, vt[i].getPos() - vt[i-1].getPos() - 1);
        }
        return ans;
    }
};


// a neat version
class Solution {
public:
    int longestValidParentheses(string s) {
        vector< pair<char, int> > v;
        for(int i = 0; i < s.size(); i++) {
            if( s[i] == ')' && (v.size() > 0 && v.back().first == '(' ) ) v.pop_back();
            else {
                v.push_back( make_pair(s[i], i) );
            }
        }
        
        int mx = 0, l = 0, r = s.size();
        while( !v.empty() ) {
            mx = max(mx, r - v.back().second - 1);
            r = v.back().second;
            v.pop_back();
        }
        mx = max(mx, r);
        return mx;
    }
};
