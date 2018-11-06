// Time complexity: O(n*lgn*lgn)
// see here:   https://en.wikipedia.org/wiki/Divergence_of_the_sum_of_the_reciprocals_of_the_primes
class Solution {
public:
    int countPrimes(int n) {
        vector<int> v(n,0);
        int ans = 0;
        for(int i = 2; i < n; i++ ) {
            if( !v[i]){
                for(int j = 2; j * i < n; j++ ) v[j*i] = 1;
                ans ++;
            }
        }
        return ans;
    }
};
