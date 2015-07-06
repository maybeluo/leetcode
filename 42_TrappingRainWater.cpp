// result: the minimum of left and right maximum value.

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,-1), right(n,-1);
        for(int i = 0; i < n; i++) {
            left[i] = i ? max(left[i-1], height[i]) : height[i];
        }
        for(int i = n - 1; i >= 0; i--) {
            right[i] = (i== n -1) ? height[i] : max(right[i + 1], height[i]);
        }
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += min(left[i], right[i]) - height[i];
        }
        return sum;
    }
};
