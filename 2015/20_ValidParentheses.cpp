// simulation with stack.
// RE because of missing "!vc.empty()" in L12, L16, L20

class Solution {
public:
    bool isValid(string s) {
        vector<char> vc;
        vc.clear();
        for(string::iterator it = s.begin(); it != s.end(); it++){
            if( *it == '(' || ( *it == '[' || *it == '{' ) ) vc.push_back(*it);
            if( *it == ')' ){
                if( !vc.empty() && vc.back() == '(' ) vc.pop_back();
                else return false;
            }
            if( *it == ']' ){
                if( !vc.empty() && vc.back() == '[' ) vc.pop_back();
                else return false;
            }
            if( *it == '}' ){
                if( !vc.empty() && vc.back() == '{' ) vc.pop_back();
                else return false;
            }
        }
        if(vc.size() < 1) return true;
        else return false;
    }
};
