// The tricky is: "00" and "000" are invalid. Thus L66 is essential.

class Solution {
public:
    template <typename T>
     string numberToString( T Number ) {
        ostringstream ss;
        ss << Number;
        return ss.str();
    }

    template <typename T>
     T stringToNumber( string &Text ) {
        istringstream ss(Text);
        T result;
        return ss >> result ? result : 0;
    }

    void dfs(vector< vector<int> >& vs, vector<int> vi, string s, int seg, int pos) {
        if(seg >= 3){
            string cs = s.substr(pos, s.size()-pos);
            int t = stringToNumber<int>(cs);
            if( t >= 0 && t < 256 ) {
                vi.push_back(t);
                vs.push_back(vi);
            }
            return ;
        }
        for(int i = 1; i <= 3; i++) {
            if( pos + i >= s.size() ) break;
            string cs = s.substr(pos, i);
            int t = stringToNumber<int>(cs);
            if(t >= 0 && t < 256) {
                //if(seg == 0 && t == 0) continue;
                vi.push_back(t);
                dfs(vs, vi, s, seg + 1, pos + i);
                vi.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        ans.clear();
        if( s.size() < 4) return ans;
        vector< vector<int> > vs;
        vs.clear();
        vector<int> vi;
        vi.clear();

        dfs(vs, vi, s, 0, 0);

        set<string> strSet;
        strSet.clear();
        for( vector< vector<int> >::iterator ivv = vs.begin(); ivv != vs.end(); ivv++ ){
            vector<int> vt(*ivv);
            string st = "";
            for(int i = 0; i < vt.size() - 1; i++){
                st += ( numberToString(vt[i]) + '.' );
            }
            st += numberToString(vt[vt.size() - 1]);
            strSet.insert(st);
        }
        for(set<string>::iterator it = strSet.begin(); it != strSet.end(); it++){
            string st = *it;
            if(st.size() - 3 == s.size()) {
                ans.push_back(st);
                //cout<<st<<endl;
            }
        }
        return ans;
    }
};
