// bitset to enumerate.

class Solution {
public:
    const static int maxNUM = 1000;
    void dfs(vector<vector<int>>& vv, bitset<maxNUM>& bt, int pos, int n, int k) {
        if(pos > n || bt.count() > k) return ;
        if(bt.count() == k && pos == n){
            string ans = bt.to_string();
            vector<int> vt;
            vt.clear();
            for(int i = 0; i < n; i++) {
                if(ans[i] == '1') vt.push_back(i + 1);
            }
            vv.push_back(vt);
            return ;
        }
        bt.flip(maxNUM - pos - 1);
        dfs(vv, bt, pos + 1, n, k);
        bt.flip(maxNUM - pos - 1);
        dfs(vv, bt, pos + 1, n, k);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> vv;
        vv.clear();
        if(n < k) return vv;
        assert(n <= maxNUM);
        
        bitset<maxNUM> bt;
        bt.reset();
        dfs(vv, bt, 0, n, k);
        return vv;
    }
};
