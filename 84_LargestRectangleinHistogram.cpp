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
