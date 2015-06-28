// Remove duplicate without using "set".

class Solution {
public:

    void dfs(vector< vector<int> > & ans, vector<int>& candidates, vector<int>& v, int pos, int tsum, int target){
        if( tsum > target )
            return;
        if( pos <= candidates.size() && tsum == target ) {
            vector<int> vt(v);
            ans.push_back(vt);
            return ;
        }
        if( pos >= candidates.size() ) return;
        
        int j = pos + 1;
        while( j < candidates.size() && candidates[j-1] == candidates[j] ) j ++;
        for(int k = 0; k <= j - pos; k++) {
            for(int p = 0; p < k; p++) v.push_back(candidates[pos]);
            dfs(ans, candidates, v, j, tsum + k*candidates[pos], target);
            for(int p = 0; p < k; p++) v.pop_back();
        }

    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector< vector<int> > vs;
        vs.clear();
        if( n < 1 ) return vs;
        
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        v.clear();
        dfs(vs, candidates, v, 0, 0, target);
        return vs;
    }
    
};
