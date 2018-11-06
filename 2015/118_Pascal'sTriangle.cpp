// Need to find a more elegant way to avoid overflow, instead of using "long long"

class Solution {
public:
    typedef long  long LL;
    vector<int> getRow(int rowIndex) {
        vector<int> vt;
        vt.clear();
        vt.push_back(1);
        LL pre = 1;
        for(int i = 0; i < rowIndex; i++){
            LL t = pre * (rowIndex - i) /(i + 1);
            vt.push_back(t);
            pre = t;
        }
        return vt;
    }
};
