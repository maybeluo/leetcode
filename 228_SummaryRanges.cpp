// WA 1 times: L18, "j + 1 < n", not "j < n"

class Solution {
public:
    string int2String(int a) {
         ostringstream ss;
         ss << a;
         return ss.str();
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> answer;
        answer.clear();
        int i = 0, j = 0;
        while(i < n) {
            j = i;
            while( j + 1 < n && nums[j] + 1 == nums[j + 1] ) {
                j ++;
            }
            string stmp = int2String(nums[i]);
            if(i != j) {
                stmp += "->";
                stmp += int2String(nums[j]);
            }
            answer.push_back(stmp);
            i = j + 1;
        }
        return answer;
    }
};
