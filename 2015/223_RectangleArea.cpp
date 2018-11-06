class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    	int ans = abs(C - A) * abs(D - B) + abs(G - E) * abs(H - F);
    	int l = max(A, E), r = min(C, G), u = min(D, H), d = max(B, F);
    	if( l < r && d < u) ans -= (r - l)*(u -  d);
    	return ans;
    }
};
