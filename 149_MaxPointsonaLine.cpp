// Time complexity: O(N^2*logN)
// Fixed one point, sort other point by the slope with respect to the fixed point.
// WA 1 times: L34 is essential when there are only points duplicate with the given point.

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if(n <= 1) return n;
        
        int mx = 0, smp = 0;
        const double maxSlope = 1e50;//parrel with y axis
        vector<double> vt;
        
        for(int i = 0; i < n; i++) {
            int x0 = points[i].x, y0 = points[i].y;
            vt.clear();
            smp = 0;
            
            for(int j = i; j < n; j++){
                if( points[j].x == x0 && points[j].y == y0 ) smp ++;
                else if( points[j].x == x0 ) vt.push_back(maxSlope);
                else vt.push_back( (points[j].y - y0)*1.0/(points[j].x - x0) );
            }
            mx = max(mx, smp);
            
            sort(vt.begin(), vt.end());
            int p, k;
            for(k = 0; k < vt.size(); k = p + 1){
                for(p = k; p < vt.size() - 1; p++){
                    if( vt[p] != vt[p + 1]) break;
                }
                mx = max(mx, p - k + 1 + smp);
            }
        }
        
        return mx;
    }
};
