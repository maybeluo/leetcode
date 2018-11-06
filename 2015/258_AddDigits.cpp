// 1 + (n-1)%9
// see here: https://en.wikipedia.org/wiki/Digital_root#Abstract_multiplication_of_digital_roots

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        return 1 + (num - 1) % 9;
    }
};
