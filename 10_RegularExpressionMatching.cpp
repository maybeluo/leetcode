// a backtracking version
class Solution {
public:
    bool dfs(const string& s, const string& t, int ls, int lt) {
    	if(ls > s.size() || lt > t.size() ) return false;
    	if( lt >= t.size() ) return (ls == s.size()) ? true : false;
    	if( ls < s.size() && s.substr(ls) == t.substr(lt) ) return true;
    	
    	if(t[lt] == '.'){
    		if(lt + 1 < t.size() && t[lt + 1] == '*') { // .*
    			bool flag = false;
    			for(int i = ls; i <= s.size() && !flag; i++) {
    				flag |= dfs(s, t, i, lt + 2);
    			}
    			return flag;
    		}
    		else return dfs(s, t, ls + 1, lt + 1);
    	}
    	else{
    		if(lt + 1 < t.size() && t[lt + 1] == '*') { //[a-z]*
    			bool flag = dfs(s, t, ls, lt + 2); // zero times
    			for(int i = ls; i < s.size() && !flag; i++) {
    				if(s[i] == t[lt]) flag |= dfs(s, t, i + 1, lt + 2);
    				else break;
    			}
    			return flag;
    		}
    		else{
    			if(ls < s.size() && s[ls] == t[lt]) return dfs(s, t, ls + 1, lt + 1);
    			else return false;
    		}
    	}
    }
    
    bool isMatch(string s, string t) {
    	return dfs(s, t, 0, 0);
    }
};
