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
