class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int ne = prerequisites.size();

        vector< vector<int> > vv(numCourses);
        for(int i = 0; i < numCourses; i++) {
            vector<int> v;
            v.clear();
            vv.push_back(v);
        }
        
        vector<int> deg(numCourses, 0);
        for(int i = 0; i < ne; i++) {
            vv[ prerequisites[i].first ].push_back( prerequisites[i].second );
            deg[ prerequisites[i].second ] ++;
        }
        
        vector<int> ans, vis;
        ans.clear();
        vis.clear();
        
        for(int i = 0; i < numCourses; i++) {
            if(deg[i] == 0) {
                vis.push_back(i);
            }
        }
        
        while( !vis.empty() ) {
            int c = vis.back();
            vis.pop_back();
            ans.push_back(c);
            for(int i = 0; i < vv[c].size(); i++) {
                deg[ vv[c][i] ] --;
                if( deg[ vv[c][i] ] == 0 ) {
                    vis.push_back( vv[c][i] );
                }
            }
        }
        if(ans.size() < numCourses) return false;
        //for(int i = 0; i < numCourses; i++) {
        //    if(deg[i] > 0) return false;
        //}
        return true;
        
    }
};
