/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef long long LL;

class Solution {
public:
    void dfs(TreeNode* r, LL& ans, LL pre) {
        if(r->left == NULL && r->right == NULL) {
            ans += (pre*10 + r->val);
            return ;
        }
        pre = pre * 10 + r->val;
        if(r->left != NULL) {
            dfs(r->left, ans, pre);
        }
        if(r->right != NULL) {
            dfs(r->right, ans, pre);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        LL ans = 0, pre = 0;
        dfs(root, ans, pre);
        return ans;
    }
};

// version 2.
void dfs(TreeNode* root, int cnt, int& sum) {
	if(root == NULL) return ;
    if(root -> left == NULL && root -> right == NULL) {
    	sum += ( cnt *10 + root -> val);
    	return ;
    }
    dfs(root -> left, cnt *10 + root -> val, sum);
    dfs(root -> right, cnt *10 + root -> val, sum);
}

int sumNumbers(TreeNode *root) {
	int sum = 0;
	dfs(root, 0, sum);
	return sum;
}
