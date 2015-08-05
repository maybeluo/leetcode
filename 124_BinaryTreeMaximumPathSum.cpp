// WA: L18 & L19 are Wrong, it will take both branches into consideration.

class Solution {
public:
  
    // The return value:
    //  1. the max path sum with current node 'root';
    //  2. only account one branch, not two branches, see L18 - L21.
    int dfs(TreeNode* root, int& mx) {
        if(root->left == NULL && root->right == NULL) {
            mx = max(mx, root->val);
            return root->val;
        }
        int ret; 
        if(root->left != NULL && root->right != NULL) {
            int vl = dfs(root->left, mx);
            int vr = dfs(root->right, mx);
            // ret = max( root->val, max( root->val + vl + vr, max(root->val + vl, root->val + vr) ) );
            // mx = max(mx, ret);
            ret = max( root->val, max(root->val + vl, root->val + vr) );
            mx = max( mx, max( root->val, max( root->val + vl + vr, max(root->val + vl, root->val + vr) ) ) );
        }
        else if(root->left != NULL) {
            int vl = dfs(root->left, mx);
            ret = max( root->val, root->val + vl );
            mx = max(mx, ret);
        }
        else{
            int vr = dfs(root->right, mx);
            ret = max( root->val, root->val + vr );
            mx = max(mx, ret);
        }
        return ret;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int mx = 0 - 0x7fffffff;
        dfs(root, mx);
        return mx;
    }
};

//version 2.
// MUST return an value in L52!!!!
int dfs(TreeNode* root, int& mx) {
	if(root == NULL) return 0;
	int left = dfs(root -> left, mx);
	int right = dfs(root -> right, mx);
	int ret = max( root -> val, max(left + root -> val, right + root -> val) );
	mx = max( mx, max(ret, left + right + root -> val) );
	return ret; // must have an return value!!! otherwise, will return a random value and hard to debug
}

int maxPathSum( TreeNode *root) {
	int mx = 0 - 0x7fffffff;
	dfs(root, mx);
	return mx;
}
