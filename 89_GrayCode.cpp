// find rules of gray code.

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.clear();
        
        ans.push_back(0);
        if(n < 1) return ans;
        
        ans.push_back(1);
        
        int k = 2; // k = 2^(i-1)
        for(int i = 2; i <= n; i++) {
            // add the 2^(i-1) to the last gray code set from large to small. 
            for(int j = k - 1; j >= 0; j--) {
                int val = ans[j] + k;
                ans.push_back(val);
            }
            k *= 2;
        }
        
        return ans;
    }
};
