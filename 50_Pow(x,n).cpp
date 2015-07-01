class Solution {
public:
    double myPow(double x, int n) {
        
        if(x == 0.0) return 0.0;
        if(n == 0) return 1;
        int flag = 0;
        if(n < 0){
            flag = 1;
            n = -n;
        }
        
        double base = x, r = 1;
        while(n > 0){
            if(n%2 == 1) r *= base;
            base *= base;
            n /= 2;
        }
        
        if(flag == 1) return 1.0/r;
        else return r;
    }
};
