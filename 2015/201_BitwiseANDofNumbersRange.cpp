// If m < 2^k < n, then the result of AND in range [m, n] must be 0.

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n) return m;
        
        const int pow2[32] = {0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
        
        int i, j, ans = 0;
        while( m > 0 ){
            for(i = 0; i < 32; i++) {
                if( pow2[i] > m  ) break;
            }
            for(j = 0; j < 32; j++) {
                if( pow2[j] > n ) break;
            }
            
            int im = i - 1, in = j - 1;
            if(im != in) 
                break;
            else{
                ans += pow2[im];
                m -= pow2[im];
                n -= pow2[in];
            }
        }
        return ans;
    }
};

// another version
// This solution just calculate the unchanged bit part juring the bitwise-and all numbers between m and n.
// Because m and n is the min and max number in the range,so their unchanged part will be the same in other numbers in the range.
int rangeBitwiseAnd(int m, int n) {
    int mask = ~0;
    while (mask && (m & mask) != (n & mask))
        mask <<= 1; 
    return m & mask;
}
