// See http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        vector<int> v;
        v.clear();
        int ind = 0, mx = 0;
        while(ind < n) {
            if( v.empty() || height[ v[v.size() - 1] ] <= height[ind] ) {
                v.push_back(ind);
                ind ++;
            }
            else {
                int k = v.back();
                v.pop_back();
                int cur = height[k] * ( v.empty() ? ind : ind - v[v.size()-1] - 1 );
                mx = max(mx, cur);
            }
        }
        while( !v.empty() ) {
            int k = v.back();
            v.pop_back();
            int cur = height[k] * ( v.empty() ? ind : ind - v[v.size()-1] - 1 );
            mx = max(mx, cur);
        }
        return mx;
    }
};

// second version
int largestRectangleArea(vector<int> & height) {
	int n = height.size(), mx = 0;
	int l = -1, r = n, i = 0;
	vector< pair<int, int> > v;
	for(i = 0; i < n; i++) {
		while( !v.empty() && v.back().first > height[i] ) {
			int left = (v.size() > 1) ? v[v.size() - 2].second : l;
			mx = max(mx, (i - left - 1) * v.back().first);
			v.pop_back(); 
		}
		v.push_back( make_pair(height[i], i) );
	}
	while( !v.empty() ){
		int left = (v.size() > 1) ? v[v.size() - 1].second : l;
		mx = max(mx, (r - left - 1)*v.back().first);
		v.pop_back();
	}
	return mx;
}
