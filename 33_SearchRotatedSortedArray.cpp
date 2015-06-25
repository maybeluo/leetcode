// Beautiful! Find the pivot first, then binary search two sorted part.
// The process of finding the pivot is rather fragile.
// time complexity: O(log n)
// WA 3 times:
//  1) L16: should be "l<=r", NOT "l<r". Otherwise, the situation of nums[l] (=nums[r]) isn't processed.
//  2) L42: ">=0", NOT ">0".
//  3) L32: ">=", NOT ">". This really makes a difference. Think it over! Take [1,3] and [3,1] for example.

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int binarySearch(vector<int>& nums, int target, int l, int r){
    if( l == r && nums[l] == target ) return l;
    while( l <= r ){
        int mid = (l + r)/2;
        if( nums[mid] == target ) return mid;
        else if( nums[mid] > target ) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    if( n < 1 ) return -1;

    int l = 0, r = n - 1;
    while(l < r){
        int mid = (l + r)/2;
        if( nums[mid] >= nums[0] ) l = mid + 1;
        else r = mid;
        // printf("l:%d  mid:%d  r:%d\n", l, mid, r);
    }
    // printf("l:%d  r:%d\n", l, r);
    int pv = l;
    if( pv == 0 ) return binarySearch(nums, target, 0, n - 1);
    int left = binarySearch(nums, target, 0, pv - 1);
    int right = binarySearch(nums, target, pv, n - 1);
    // printf("pv:%d  left:%d  right:%d\n", pv, left, right);
    if( max(left, right) >= 0 ) return max(left, right);
    else return -1;
}

int main()
{
    int n, target;
    vector<int> vt;
    while( scanf("%d %d", &n, &target) != EOF ){
        vt.clear();
        for(int i = 0; i < n; i++){
            int t;
            scanf("%d", &t);
            vt.push_back(t);
        }
        printf("%d\n", search(vt, target));
    }
    return 0;
}
