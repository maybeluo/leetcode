// see solution here. https://leetcode.com/discuss/21027/sharing-my-straightforward-c-solution-with-explanation
string getPermutation(int n, int k) {
	vector<int> fact(n + 1, 1);
	for(int i = 1; i <= n; i++) fact[i] = fact[i-1] * i;
	vector<char> nums(n);
	for(int i = 0; i < n; i++) nums[i] = (i + 1 + '0');
	string ans = "";
	k --;
	while(n > 0) {
		n--;
		int ind = k/fact[n];
		ans += nums[ind];
		nums.erase(nums.begin() + ind);
		k %= fact[n];
	}
	return ans;
}
