// a very direct and ugly way..., Time complexity is O(n*m)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        ans.clear();
        if(s.size() < 1 || words.size() < 1) return ans;
        
        int n = s.size(), m = words.size(), d = words[0].size();
        if(n < m * d ) return ans;

        unordered_map<string, int> vis, dict;
        dict.clear();
        vis.clear();
        
        for(int i = 0; i < m; i++)  dict[ words[i] ] += 1;
        
        for(int i = 0; i + m * d <= n; i ++) {
            vis.clear();
            string now = s.substr(i, d);
            if(dict.find(now) != dict.end() ) {
                vis[now] += 1;
                for(int j = 1; j < m; j++) {
                    string tmp = s.substr( i + j * d, d);
                    if( dict.find(tmp) != dict.end() ) {
                        vis[tmp] += 1;
                    }
                    else {
                        break;
                    }
                }
                if(vis == dict) ans.push_back(i);
            }
        }
        return ans;
    }
};

