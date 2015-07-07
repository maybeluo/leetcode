// L10: from end to head.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size();
        vector<int> v(h, 0);
        for(int i = 0; i < h; i++) {
            int m = triangle[i].size();
            for(int j = m - 1; j >= 0; j--) {
                if(j == m - 1)
                    v[j] = v[j-1] + triangle[i][j];
                else if(j == 0)
                    v[j] = v[j] + triangle[i][j];
                else
                    v[j] = min(v[j], v[j - 1]) + triangle[i][j];
            }
        }
        int mn = 0x5fffffff;
        for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
            mn = min(mn, *it);
        }
        return mn;
    }
};
