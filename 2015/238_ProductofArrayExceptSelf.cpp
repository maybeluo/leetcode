// O(1) space: 
//    it Actually use the result vector to stimuliate "pre" and "aft" in L30.

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size(), cnt = 1;
    if(n < 1) return nums;
    
    vector<int> ans(n,1);
    
    cnt = 1;
    for(int i = 1; i < n; i++) {
        cnt *= nums[i-1];
        ans[i] = cnt; // previous product of [0 ~ (i-1)]
    }
    
    cnt = 1;
    for(int i = n-2; i >= 0; i-- ) {
        cnt *= nums[i + 1]; // product of [i+1 ~ n-1]
        ans[i] *= cnt;
    }
    
    return ans;
}

// O(n) space
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    if(n < 1) return nums;
    
    vector<int> pre(n, 1), aft(n, 1);
    
    pre[0] = nums[0];
    for(int i = 1; i < n; i++) {
        pre[i] = pre[i-1] * nums[i];
    }
    
    aft[n-1] = nums[n-1];
    for(int i = n-2; i >= 0; i-- ) {
        aft[i] = aft[i+1] * nums[i];
    }
    
    vector<int> ans(n,1);
    ans[0] = aft[1];
    ans[n-1] = pre[n-2];
    for(int i = 1; i < n - 1; i++) {
        ans[i] = pre[i-1] * aft[i+1];
    }
    return ans;
}
