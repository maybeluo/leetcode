// WA many times.
// The termination condition of dfs should be a leaf, i.e. both left and right child are NULL, see L20.
//  not a node who is NULL, see L58 & L59.
// See wrong version at the bottom. Learn the lesson!

// AC version.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void dfs(vector< vector<int> >& vv, vector<int> vt, TreeNode* nt, int cnt, int sum) {
        if(nt->left == NULL && nt->right == NULL){
            if(cnt + nt->val == sum){
                vt.push_back(nt->val);
                vv.push_back(vt);
            }
            return ;
        }
        vt.push_back(nt->val);
        if(nt->left != NULL){
            dfs(vv, vt, nt->left, cnt + nt->val, sum);
        }
        if(nt->right != NULL){
            dfs(vv, vt, nt->right, cnt + nt->val, sum);
        }
        vt.pop_back();
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector< vector<int> > vv;
        vv.clear();
        vector<int> vt;
        vt.clear();
        
        if(root == NULL) return vv;

        dfs(vv, vt, root, 0, sum);

        return vv;
    }
};


// Wrong version
class Solution {
public:

    void dfs(vector< vector<int> >& vv, vector<int> vt, TreeNode* nt, int cnt, int sum, int dep) {
        if( nt == NULL && cnt != sum ) return ;
        if(nt == NULL && cnt == sum ){
            vv.push_back(vt);
            return ;
        }
        vt.push_back(nt->val);
        dfs(vv, vt, nt->left, cnt + nt->val, sum, dep+1);
        dfs(vv, vt, nt->right, cnt + nt->val, sum, dep+1);
        vt.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector< vector<int> > vv;
        vv.clear();
        vector<int> vt;
        vt.clear();
        
        if(root == NULL) return vv;

        dfs(vv, vt, root, 0, sum, 0);

        return vv;
    }
};

// version 2.
void dfs(vector< vector<int> >& vv, vector<int>& v, TreeNode* root, int cnt, int target) {
	if( root == NULL ) return ;
	if( root -> left == NULL && root -> right == NULL ) {
    	if( cnt + root -> val == target ) {
        	vector<int> vt(v.begin(), v.end() );
        	vt.push_back(root -> val);
        	vv.push_back(vt);
        }
        return ;
    }
	v.push_back( root -> val );
	dfs(vv, v, root -> left, cnt + root -> val, target );
	dfs(vv, v, root -> right, cnt + root -> val, target );
	v.pop_back();
} 

vector< vector<int> > pathSum( TreeNode* root, int sum) {
	vector< vector<int> > vv;
	vv.clear();
	vector<int> v;
	v.clear();
	dfs(vv, v, root, 0, sum);
	return vv;
}
