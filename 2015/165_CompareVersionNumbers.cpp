class Solution {
public:
    template<class T>
    T stringToNumber(string text) {
        istringstream ss(text);
        T result;
        return ss>>result ? result : 0;
    }
    
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, k = 0, a = version1.size(), b = version2.size();
        while( i < a && j < b) {
            for(k = i; k < a; k++) {
                if(version1[k] < '0' || version1[k] > '9' ) break;
            }
            string s1 = version1.substr(i, k - i);
            i = k + 1;
            
            for(k = j; k < b; k++) {
                if(version2[k] < '0' || version2[k] > '9' ) break;
            }
            string s2 = version2.substr(j, k - j);
            j = k + 1;
            
            int v1 = stringToNumber<int>(s1);
            int v2 = stringToNumber<int>(s2);
            if(v1 > v2) return 1;
            if(v1 < v2) return -1;
        }
        
        // handle cases like: '2', '2.0', '2.0.0.52'
        if(i < a) {
            while(i < a) {
                for(k = i; k < a; k++) {
                    if(version1[k] < '0' || version1[k] > '9' ) break;
                }
                string s1 = version1.substr(i, k - i);
                i = k + 1;
                int v1 = stringToNumber<int>(s1);
                if(v1 > 0) return 1;
            }
        }
        if(j < b) {
            while(j < b) {
                for(k = j; k < b; k++) {
                    if(version2[k] < '0' || version2[k] > '9' ) break;
                }
                string s2 = version2.substr(j, k - j);
                j = k + 1;
                int v2 = stringToNumber<int>(s2);
                if(v2 > 0) return -1;
            }
        }
        return 0;
    }
};
