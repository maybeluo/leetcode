// Anagram: An anagram is a type of word play, the result of rearranging the letters of a word or phrase to produce a new word or phrase, 
//    using all the original letters exactly once. See wikipedia: https://en.wikipedia.org/wiki/Anagram

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> ans;
        ans.clear();
        int n = strs.size();
        if( n < 1 ) return ans;

        map<string, vector<string> > mp;
        mp.clear();

        map<string, vector<string> >::iterator im;
        for(int i = 0; i < n; i++) {
            string sa = strs[i];
            string key = sa;
            sort(key.begin(), key.end());
            im = mp.find(key);
            if( im != mp.end() ){
                vector<string> vt( im->second );
                vt.push_back(sa);
                mp[key] = vt;
            }
            else{
                vector<string> vt(1, sa);
                mp[key] = vt;
            }
        }

        for(im = mp.begin(); im != mp.end(); im++) {
            vector<string> vt(im->second);
            if(vt.size() > 1){
                for(vector<string>::iterator iv = vt.begin(); iv != vt.end(); iv++) {
                    ans.push_back(*iv);
                }
            }
        }
        return ans;
    }
};
