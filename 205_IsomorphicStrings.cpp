class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_set<char> vis;
        mp.clear();
        vis.clear();
        
        for(int i = 0; i < s.size(); i++) {
            if( mp.find(s[i]) == mp.end() && vis.find(t[i]) == vis.end() ) {
                mp[ s[i] ] = t[i];
                vis.insert(t[i]);
            }
            if( mp.find(s[i]) == mp.end() || mp[ s[i] ] !=  t[i]) return false;
        }

        return true;
    }
};
