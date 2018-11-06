// WA 2 times:
//  1) step out of the while-loop in L41 immediately when "if( abs(vn[i].pos - vn[j].pos) > k )". Confused by the indexes.
//  2) overflow. use "long long"

class Solution {
public:
    typedef long long LL;
    class Node{
    public:
        LL val;
        LL pos;
        
        Node(){}
        Node(LL t_val, LL t_pos){
            val = t_val;
            pos = t_pos;
        }
    };
    
    static bool nodeCmp(const Node& a, const Node& b){
        if( (a.val < b.val) || (a.val == b.val && a.pos < b.pos) ) return true;
        else return false;
    }
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if( k < 1 ) return false;
        int n = nums.size();
        if( n < 1) return true;
        
        vector<Node> vn;
        vn.clear();
        
        for(int i = 0; i < n; i++){
            Node pt(nums[i], i);
            vn.push_back(pt);
        }
        sort(vn.begin(), vn.end(), nodeCmp);
        
        for(int i = 0; i < n; i++){
            int j = i + 1;
            while( j < n){
                if( vn[j].val - vn[i].val <= t ) {
                    if( abs(vn[i].pos - vn[j].pos) <= k ) return true;
                }
                else break;
                j ++;
            }
        }
        return false;
    }
};
