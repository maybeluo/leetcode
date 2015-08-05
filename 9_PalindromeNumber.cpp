class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        int a = x, b = 0;
        while(a > 0) {
            b = ( b*10 + a%10 );
            a /= 10;
        }
        if(b == x)  return true;
        else return false;
    }
};

// version 2
typedef long long LL;
bool isPalindrome(int x) {
	LL y = 0, a = x;
	while(a > 0) {
    	int b = a %10;
    	y = y *10 + b;
    	a /= 10;
    }
    if( x - y == 0) return true;
    else return false;
}
