// Depth First Search
class Solution {
public:
    vector<string> intilize(){
        vector<string> vt;
        vt.clear();
        vt.push_back("");
        vt.push_back("");
        vt.push_back("abc");
        vt.push_back("def");
        vt.push_back("ghi");
        vt.push_back("jkl");
        vt.push_back("mno");
        vt.push_back("pqrs");
        vt.push_back("tuv");
        vt.push_back("wxyz");
        return vt;
    }
    
    void dfs( vector<string>& av, vector<string>& idv, string digits, string ans, int pos ){
        if( pos == digits.size() - 1 ){
            string st = idv[ digits[pos] - '0' ];
            for(int i = 0; i < st.size(); i++){
                av.push_back( ans + st[i] );
            }
            return ;
        }
        string st = idv[ digits[pos] - '0' ];
        for(int i = 0; i < st.size(); i++){
            dfs( av, idv, digits, ans+st[i], pos + 1 );
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> idv = intilize();
        vector<string> ans;
        ans.clear();
        if(digits.size() < 1) return ans;
        dfs(ans, idv, digits, "", 0);
        return ans;
    }

};
