class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            ans = ans*26 + (s[i] - 'A' + 1);
        }
        return ans;
    }
};
