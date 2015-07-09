// TLE before adding L28 & L36

class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
    	int n = nums.size();
    	int mx = 0;
    	vector<int> vis(n, 0);
    	unordered_map<int, int> hmap;
    	hmap.clear();
    	for(int i = 0; i < n; i++) {
    		hmap[ nums[i] ] = i;
    	}
    	int cur, cnt;
    	unordered_map<int, int>::iterator it;
    	for(int i = 0; i < n; i++) {
    		if(!vis[i]) {
    			vis[i] = 1;
    			cnt = 1;
    			cur = nums[i];
    			while( 1 ) {
    				it = hmap.find(cur-1);
    				if(it == hmap.end() ) break;
    				vis[it->second] = 1;
    				hmap.erase(it);
    				cur --;
    				cnt ++;
    			}
    			
    			cur = nums[i];
    			while( 1 ) {
    				it = hmap.find(cur+1);
    				if(it == hmap.end() ) break;
    				vis[it->second] = 1;
    				hmap.erase(it);
    				cur ++;
    				cnt ++;
    			}
    		}
    		mx = max(cnt, mx);
    	}
    	return mx;
    }
};
