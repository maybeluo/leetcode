class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        ans.clear();
        
        stack< pair<TreeNode*, int> > s;
        s.push( make_pair(root, 0) );
        while( !s.empty() ) {
            TreeNode* now = s.top().first;
            if( now == NULL ){
                s.pop();
            }
            else {
                switch( s.top().second ++ ) {
                    case 0:
                        s.push( make_pair(now -> left, 0) );
                        break;
                    case 1:
                        s.pop();
                        ans.push_back(now -> val);
                        s.push( make_pair(now -> right, 0) );
                        break;
                }
            }
        }
        return ans;
    }
};
