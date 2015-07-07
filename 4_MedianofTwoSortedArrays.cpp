// Divide and conquer, not binary search.

class Solution {
public:
    int findk(int* a, int* b, int lena, int lenb, int k) {
        if( lena > lenb ) {
            return findk(b, a, lenb, lena, k);
        }
        
        if( lena == 0 ) {
            return b[k-1];
        }
        if( k == 1 ) {
            return min(a[0], b[0]);
        }

        int pa = min(k/2, lena);
        int pb = k - pa;
        if( a[pa - 1] < b[pb - 1] ){
            return findk(a + pa, b, lena - pa, pb, k - pa);
        }
        else{
            return findk(a, b + pb, lena, lenb - pb, k - pb);
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int *A = NULL, *B = NULL;
        if(n > 0) A = &nums1[0];
        if(m > 0) B = &nums2[0];
        
        if( (n + m)%2 ){
            return findk(A, B, n, m, (n + m + 1)/2);
        }
        else{
            return ( findk( A, B, n, m, (n + m)/2 ) + findk( A, B, n, m, (n + m)/2 + 1 ) )/2.0;
        }
    }
};
