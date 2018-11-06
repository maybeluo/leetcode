//Do not take duplicates into consideration

class Solution {
public:
    void dfs(vector< vector<int> >& vs, vector<int>& v, int pos ) {
        if( pos >= v.size() ) {
            vs.push_back(v);
            return ;
        }
        dfs(vs, v, pos + 1);
        for(int i = pos + 1; i < v.size(); i++) {
            swap(v[i], v[pos]);
            dfs(vs, v, pos + 1);
            swap(v[i], v[pos]);
        }
    }
    
    vector< vector<int> > permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector< vector<int> > vs;
        vs.clear();
        dfs( vs, nums, 0 );
        return vs;
    }

};
