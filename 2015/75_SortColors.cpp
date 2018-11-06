// See http://blog.csdn.net/zxzxy1988/article/details/8596144
// I've thought of three pointers and the idea of partition sort, but cannot handle the pointers well.
// The key is no L19.

class Solution {
public:
    void sortColors(vector<int>& nums) {
		int n = nums.size();
		if (n < 1) return;
		int i = 0, l = 0, r = n -1;
		while( i <= r) {
			if(nums[i] < 1){
				swap(nums[i], nums[l]);
				i ++;
				l ++;
			}
			else if(nums[i] > 1) {
				swap(nums[i], nums[r]);
				// i ++;
				r --;
			}
			else
				i ++;
		}
		return ;
	}
};
