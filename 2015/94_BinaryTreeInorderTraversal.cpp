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

// version 2
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        ans.clear();
        
        stack< TreeNode* > s;
        TreeNode* p = root;
        while( p != NULL || !s.empty() ) {
            if( p != NULL ){
                s.push(p);
                p = p -> left;
            }
            else {
                p = s.top();
                ans.push_back(p -> val);
                s.pop();
                p = p -> right;
            }
        }
        return ans;
    }
};
