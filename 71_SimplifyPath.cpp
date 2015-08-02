class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ans;
        ans.clear();
        
        int n = path.size();
        int i = 0, j = 0;
        while(i < n) {
           while(i < n && path[i] == '/') i ++; // may multiple '/', take as one
           if(i >= n)   break;
           
           int d = 0;
           if(path[i] == '.') {
               while(i + d < n && path[i + d] == '.' ) d ++;
           }
           if(i + d >= n || path[i + d] == '/') { // end of current dir name
            if(d == 2 && !ans.empty()) ans.pop_back();
           	if(d > 2) ans.push_back("/" + path.substr(i, d) );
           	if(i + d >= n) break;
           	i += d;
           	continue;
           }
           
           while(i + d < n && path[i + d] != '/') d ++;
           ans.push_back( "/" + path.substr(i, d) );
           i += d;
        }
        
        string rs = "";
        if(ans.empty()) return rs = "/";
        else {
        	for(int i = 0; i < ans.size(); i++) rs += ans[i];
        }
        return rs;
    }
};
