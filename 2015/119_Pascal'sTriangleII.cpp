class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        vv.clear();
        if(numRows < 1) return vv;
        vector<int> vt(1,1);
        vv.push_back(vt);

        for(int i = 1; i < numRows; i++){
            vt.clear();
            vt.push_back(1);
            for(int j = 1; j < i; j++){
                vt.push_back( vv[i-1][j-1] + vv[i-1][j] );
            }
            vt.push_back(1);
            vv.push_back(vt);
        }
        
        return vv;
    }
};
