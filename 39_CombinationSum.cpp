// Maybe more elegant methods exists, ex. generation function. Try other methods after get all the problems done...
// The solution below is enumeration.
//   WA: because of putting L18 before L13
//   TLE: unnecessary lines: L18 & L28
//   OLE: L27 was forgotten

class Solution {
public:

    void dfs(vector< vector<int> > & ans, vector<int>& candidates, vector<int>& v, int pos, int tsum, int target){
        if( tsum > target )
            return;
        if( tsum == target ) {
            vector<int> vt(v);
            ans.push_back(vt);
            return ;
        }
        if( pos >= candidates.size() ) return;
        //for(int i = 0; i < candidates.size(); i++){
            int j = 0;
            while( tsum + j*candidates[pos] <= target ) {
                j ++;
            }
            for(int k = 0; k <= j; k++) {
                for(int p = 0; p < k; p++) v.push_back(candidates[pos]);
                dfs(ans, candidates, v, pos + 1, tsum + k*candidates[pos], target);
                for(int p = 0; p < k; p++) v.pop_back();
            }
        //}
    }
    
    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
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
