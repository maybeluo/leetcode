// Bitwise iterate the 32-bit of each element in the array, get the median of each bit. Aggregate them together is the final result.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int num_zero = 0;
            int num_ones = 0;
            for(int j = 0; j < nums.size(); j++) {
                if( (nums[j] >> i) & 1 ) num_ones ++;
                else num_zero ++;
            }
            if(num_zero < num_ones) ans += (1 << i);
        }
        return ans;
    }
};

// counting: one counter
//  You can assume that there are three "number" in the vector. Teo is the majority number, the other one is the rest of the vector.
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    if(n < 1) return -1;
    
    int a, ia = 0;
    for(int i = 0; i < n; i++) {
        if(ia == 0) {
            a = nums[i];
            ia = 1;
        }
        else if(nums[i] == a) {
            ia ++;
        }
        else {
            ia --;
        }
    }
    return a;
}

// two counters.
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    if(n < 1) return -1;
    
    int a, b, ia, ib = 0;
    a = nums[0], ia = 1;
    for(int i = 1; i < n; i++) {
        if(nums[i] == a) ia ++;
        else if(nums[i] != a && ib < 1) {//b hasn't been assigned a value
            b = nums[i];
            ib = 1;
        }
        else if(ib >= 1 && nums[i] == b) ib ++;
        else if( nums[i] != a && (ib >= 1 && nums[i] != b) ) {
            if(ia > ib) {
                b = nums[i];
                ib = 1;
            }
            else{
                a = nums[i];
                ia = 1;
            }
        }
    }
    
    if(ia > ib) return a;
    else return b;
}
