// Greedy.
//  move as far as possible when the place can move, i.e. gas[i] - cost[i] >= 0

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i, j, nZero = 0;
        
        vector<int> vis(n, 0);
        for(i = 0; i < n; ) {
            j = 1;
            if(vis[i]) continue; // has been visited
            
            // start move from here
            int cnt = gas[i] - cost[i];
            if(cnt >= 0) {
                vis[i] = 1;
                nZero ++;
                if(nZero == n) return i;
                
                // move as far as possible
                while( cnt + (gas[(i + j)%n] - cost[(i + j)%n]) >= 0 ) {
                    cnt += ( gas[(i + j)%n] - cost[(i + j)%n] );
                    vis[(i + j)%n] = 1;
                    nZero ++;
                    if(nZero == n) return i;
                    j ++;
                }
                
            }
            i += j;
        }
        return -1;
        
    }
};
