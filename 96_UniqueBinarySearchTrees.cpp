// Divide and Conquer.
// use "Memory" search to avoid TLE.

class Solution {
public:
    int dfs(int n, int l, int r, vector< vector<int> >& vv) {
    	if(l >= r) {
    		if(l == r) vv[l][r] = 1;
    		return 1;
    	}
    	int sum = 0;
    	for(int i = l; i <= r; i++) {// use i as root
    		int left, right;
    		
    		// subtree consists of [i-1, l]
    		if(l > i - 1) {
    			left = 1;
    		}
    		else {
    			if(vv[l][i-1]) left = vv[l][i-1];
    			else {
    				left = dfs(n, l, i-1, vv);
    				vv[l][i-1] = left;
    			}
    		}
    		
    		// subtree consists of [i+1, r]
    		if(i + 1 >= r) {
    			right = 1;
    		}
    		else {
    			if(vv[i+1][r]) right = vv[i+1][r];
    			else {
    				right = dfs(n, i+1, r, vv);
    				vv[i+1][r] = right;
    			}
    		}
    		sum += left*right;
    	}
    	return sum;
    }
    
    int numTrees(int n) {
    	vector< vector<int> > vv(n+1, vector<int>(n+1, 0));
    	return dfs(n, 1, n, vv);
    }  
};
