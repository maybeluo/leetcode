class Solution {
public:
    unordered_map<char, int> charToNumber = { {'A',0}, {'C',1}, {'G',2}, {'T',3} };
    // charToPow:  4^9 * charToNumber['A/B/C/D']
    unordered_map<char, int> charToPow = { {'A',0}, {'C', 262144}, {'G',524288}, {'T',786432} };
    
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> ans;
        ans.clear();
        if(n <= 10) return ans;
        
        unordered_map<int, int> visMap;
        visMap.clear();
        
        int cnt = 0;
        for(int i = 0; i < 10; i ++) {
            cnt = cnt * 4 + charToNumber[ s[i] ];
        }
        visMap[cnt] = 0;
        
        for(int i = 1; i <= n - 10; i++) {
            cnt -= ( charToPow[ s[i-1] ] );// minus the higest bit
            cnt = cnt * 4 + charToNumber[ s[i + 9] ]; // add lowest bit
            if( visMap.find(cnt) != visMap.end() ) {
                if(visMap[cnt] < 1) {
                    visMap[cnt] = 1;
                    ans.push_back( s.substr(i, 10) );
                }
            }
            else {
                visMap[cnt] = 0;
            }
        }

        return ans;
    }
};
