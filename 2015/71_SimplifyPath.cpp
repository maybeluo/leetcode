// first find out the substr between two '/', this is an easy way..

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ans;
        
        int n = path.size(), i = 0, d = 0;
        while(i < n) {
           while(i < n && path[i] == '/') i ++; // may multiple '/', take as one
           if(i >= n)   break;
           
           // handle the substr between two '/' is easy.
           d = 0;
           while(i + d < n && path[i + d] != '/' ) d ++;
           if(d == 1 && path[i] == '.') {
           	i += d;
           	continue;
           }
           else if(d == 2 && path.substr(i, d) == ".." ) {
           	if(!ans.empty()) ans.pop_back();
           }
           else ans.push_back("/" + path.substr(i,d) );
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
