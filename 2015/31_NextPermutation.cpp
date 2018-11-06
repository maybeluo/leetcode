// If the numbers are in increaseing order from right hand of the total array, i.e. a[n-1] <= a[n-2] <= ... <= a[i]
// we know it's the greatest lexicographically permuation of sequence S: a[i], ... ,a[n-1].
// Suppose we have got the index, named "p", then the problem becomes to this:
//  add one more element "a[p-1]" to S, find the next greater permutation of S': a[p-1], S
// the answer is:
//  1) find the minimum value a[j] in S which is larger than a[p-1]; ( L27 - L29 )
//  2) swap(a[j], a[p-1]), get new sequence S1; ( L24 & L30 )
//  3) find out the greatest lexicographically permuation of S1: sort S1 in increasing order. ( L21 & L31 )

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if( n < 2) return ;
        int i, j;
        for(i = n - 1; i > 0; i--){
            if( nums[i-1] < nums[i] ) break;
        }
        
        if(i <= 0) {
            sort(nums.begin(), nums.end());
        }
        else if( i >= n - 1 ) {
            swap(nums[i], nums[i-1]);
        }
        else{
            for(j = n - 1; j >= i; j--){
                if(nums[j] > nums[i-1]) break;
            }
            swap(nums[j], nums[i-1]);
            sort(nums.begin() + i, nums.end() );
        }
        
        return ;

    }
};

// a neat version
// "=" in L44 & L50.
void nextPermutation(vector<int> & nums ) {
	int n = nums.size(), i = 0, j = 0;
	i = n - 1;
	while( i - 1 >= 0 && nums[i-1] >= nums[i]) i --;// find first descending position
	if( i <= 0) {// the whole array in descending order
		reverse(nums.begin(), nums.end());
		return;
	}
	j = n - 1;
	while(j > i - 1 && nums[j] <= nums[i- 1]) j --;
	swap(nums[i - 1] ,nums[j]);
	int l = i, r = n - 1;
	while(l < r) swap(nums[l++], nums[r--]);
	return ;
}
