class Solution {
public:
    int partition(vector<int>& nums, int l, int r){
        int k = (l+r)/2;
        int pv = nums[k];
        swap(nums[k], nums[r]);
        int i = l;
        for(int j = l; j < r; j++){
            if( nums[j] < pv ){
                swap(nums[j], nums[i]);
                i ++;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }
    void quickSort(vector<int>& nums, int l, int r){
        if(l < r){
            int k = partition(nums, l, r);
            quickSort(nums, l, k - 1);
            quickSort(nums, k + 1, r);
        }
    }
    
    vector< vector<int> > threeSum( vector<int>& nums ) {
        int n = nums.size();
        quickSort(nums, 0, n - 1);
        vector< vector<int> > ans;
        ans.clear();
        for(int i = 0; i < n; i++){
            if( i > 0 && nums[i] == nums[i-1] ) continue;//Weird! TLE without this line on one sample, which works well on my PC
            int l = i + 1, r = n - 1;
            while( l < r){
                int t = nums[i] + nums[l] + nums[r];
                if( t == 0 ){
                    const int tarr[] = {nums[i], nums[l], nums[r]};
                    vector<int> vt(tarr, tarr + sizeof(tarr) / sizeof(tarr[0]));
                    ans.push_back(vt);
                    while (l < r && nums[l] == nums[l+1]) l++;
                    while (l < r && nums[r] == nums[r-1]) r--;
                    l ++;
                    r --;
                }
                else if( t > 0 ) r --;
                else l ++;
            }
        }
        return ans;
    }
};
