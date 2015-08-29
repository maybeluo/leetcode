// a detail explanation: http://www.geeksforgeeks.org/ugly-numbers/
// Just as merge sort, merge 3 sorted arrays as following:
//   1).  1*2  2*2 3*2 4*2 5*2 ...
//   2).  1*3  2*3 3*3 4*3 5*3 ...
//   3).  1*5  2*5 3*5 4*5 5*5 ...

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n + 1, 1);
        int n2 = 1, n3 = 1, n5 = 1;
        for(int i = 2; i <= n; i++) {
            int mx = min( v[n2] * 2, min( v[n3] * 3, v[n5] * 5 ) );
            if(mx == v[n2] * 2) n2 ++;
            if(mx == v[n3] * 3) n3 ++;
            if(mx == v[n5] * 5) n5 ++;
            v[i] = mx;
        }
        return v[n];
    }
};
