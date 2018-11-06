// ver 1. use priority queue in STL
int findKthLargest(vector<int>& nums, int k) {
    // heap with smallest element at the top, with size k.
    priority_queue<int, vector<int>, greater<int> > myQueue; 
    for(int i = 0; i < nums.size(); i++) {
        if( myQueue.size() < k ) {
            myQueue.push(nums[i]);
        }
        else if( nums[i] > myQueue.top() ) {
            myQueue.pop();
            myQueue.push(nums[i]);
        }
    }
    return myQueue.top();
}

// ver 2. use Divide and Conquer
class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int mid = (l + r) >> 1, i = l, j = l;
        swap(nums[mid], nums[r]);
        for(i = l, j = l; i < r; i++) {
            if(nums[i] >= nums[r]) {
                swap(nums[i], nums[j]);
                j ++;
            }
        }
        swap(nums[j], nums[r]);
        return j;
    }
    
    int findK(vector<int>& nums, int l, int r, int k) {
        if(l >= r) return nums[l];
        
        int pos = partition(nums, l, r);
        if(k == pos ) { 
            return nums[pos];
        }
        else if(k < pos ) { // left part
            return findK(nums, l, pos - 1, k);
        }
        else {
            return findK(nums, pos + 1, r, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        k --;
        return findK(nums, 0, nums.size() - 1, k);
    }
};


