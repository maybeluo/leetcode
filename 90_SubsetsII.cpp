class Solution {
public:
    const static int MAXN = 1000;
    void dfs(set< vector<int> >& vv, vector<int>& nums, bitset<MAXN>& bt, int n, int pos) {
        if(pos >= n ){
            string ans = bt.to_string();
            vector<int> vt;
            vt.clear();
            for(int i = 0; i < n; i++) {
                if(ans[i] == '1') {
                    vt.push_back(nums[i]);
                }
            }
            vv.insert(vt);
            return ;
        }
        bt.flip(MAXN - pos - 1);
        dfs(vv, nums, bt, n, pos + 1);
        bt.flip(MAXN - pos - 1);
        dfs(vv, nums, bt, n, pos + 1);
    }
    
    vector< vector<int> > subsetsWithDup(vector<int>& nums) {
        vector< vector<int> > vv;
        vv.clear();
        set< vector<int> > sv;
        sv.clear();
        int n = nums.size();
        if(n < 1) return vv;
    
        sort(nums.begin(), nums.end());
        bitset<MAXN> bt;
        bt.reset();
        dfs(sv, nums, bt, n, 0);
        for(set< vector<int> >::iterator it = sv.begin(); it != sv.end(); it++){
            vv.push_back(*it);
        }
        return vv;
    }

};
