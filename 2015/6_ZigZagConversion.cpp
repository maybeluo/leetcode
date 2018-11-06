// Reference:
//  1). https://leetcode.com/discuss/55208/if-you-are-confused-with-zigzag-pattern-come-and-see
//  2). https://leetcode.com/discuss/51476/lines-space-accepted-solution-with-detailed-explantation

// Explantation.
/* Line Number
        1                          | 2n-1                         |4n-3
        2                     2n-2 | 2n                    4n-4   |4n-2
        3               2n-3       | 2n+1               4n-5      | .
        .           .              |  .               .           | .
        i         .                |  j             secondJ       | . 
        .       n+2                |  .           3n              | .
        n-1 n+1                    |  3n-3    3n-1                | 5n-5
        n                          |  3n-2                        | 5n-4
*/

// The size of every period is defined as "cycle", 
//      cycle = (2*nRows - 2), except nRows == 1.
// In every period, every row has 2 elements, except the first row and the last row.
// Suppose the current row is i, the index of the first element is j:
//      j = i + cycle*k, k = 0, 1, 2, ...
// The index of the second element is secondJ:
//      secondJ = (j - i) + cycle - i
//   (j-i) is the start of current period, (j-i) + cycle is the start of next period.

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows < 2) return s;
        
        string ans = "";
        int circle = 2 * numRows - 2;
        for(int i = 0; i < numRows; i++) {
            for(int j = i; j < n; j += circle) {
                ans += s[j];
                int p = (j - i) + circle - i;
                if(i != 0 && i != numRows - 1 && p < n) ans += s[p];
            }
        }
        return ans;
    }
};
