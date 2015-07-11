// Bucket sort

class Solution {
public:

    int findMin(vector<int>& v) {
        int res = 0x5fffffff;
        for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
            res = min(res, *it);
        }
        return res;
    }
    
    int findMax(vector<int>& v) {
        int res = 0 - 0x5fffffff;
        for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
            res = max(res, *it);
        }
        return res;
    }
    
    int maximumGap(vector<int>& nums) {
        int ans = 0, n = nums.size();
        
        if(n < 2) return 0;
        
        int t_min = 0x5fffffff, t_max = 0 - 0x7fffffff;
        for(int i = 0; i < n; i++) {
            t_max = max( t_max, nums[i] );
            t_min = min( t_min, nums[i] );
        }
        
        int sep = ceil( (t_max - t_min)*1.0 / (n - 1) ); // maximum gap must be at least sep
        
        if(sep == 0) return 0; // all the element are the same
        
        int buckNum = (t_max - t_min)/sep + 1; // bucket number
        vector< vector<int> > vv;
        vv.clear();
        for(int i = 0; i < buckNum; i++) {
            vector<int> v;
            v.clear();
            vv.push_back(v);
        }
        
        // put element into bucket
        for(int i = 0; i < n; i++) {
            int ind = (nums[i] - t_min) / sep;
            vv[ind].push_back( nums[i] );
        }
        
        // find max gap from different bucket
        int i, j, mx_gap = 0 - 0x7fffffff;
        for(i = 0; i < buckNum; i = j) {
            if( !vv[i].empty() ) {
                for(j = i + 1; j < buckNum; j++) {
                    if( !vv[j].empty() > 0) break;
                }
                if(j < buckNum)
                    mx_gap = max(mx_gap, findMin(vv[j]) - findMax(vv[i]) );
            }
        }
        
        return mx_gap;
    }
};
