class Solution {
public:
    int getSum(vector<int>& v) {
    	int ans = 0;
    	for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    		ans += *it;
    	}
    	return ans;
    }
    
    void dfs(set< vector<int> > & sv, vector<int>& v, int b, int n, int k) {
    	if(v.size() == k) {
    		if( getSum(v) == n ) {
    			sv.insert(v);
    		}
    		return ;
    	}
    	for(int i = b; i < 10; i++) {
    		if( v.size() < k ) {
    			if( getSum(v) + i <= n ) {
    				v.push_back(i);
    				dfs(sv, v, i+1, n, k);
    				v.pop_back();
    			}
    			dfs(sv, v, i+1, n, k);
    		}
    		else break;
    	}
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
    	set< vector<int> > sv;
    	sv.clear();
    	vector< vector<int> > vv;
    	vv.clear();
    	if(k > 9) return vv;
    	
    	vector<int> v;
    	v.clear();
    	int b = 1;
    	dfs(sv, v, b, n, k);
    	for(set<vector<int>>::iterator isv = sv.begin(); isv != sv.end(); isv++) {
    		vv.push_back(*isv);
    	}
    	return vv;
    }
};
