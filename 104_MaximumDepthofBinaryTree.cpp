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
    void dfs(TreeNode* root, int& mx, int dep) {
        if(root == NULL) {
            mx = max(mx, dep);
            return ;
        }
        dfs(root->left, mx, dep + 1);
        dfs(root->right, mx, dep + 1);
    }
    
    int maxDepth(TreeNode* root) {
        int mx = 0;
        dfs(root, mx, 0);
        return mx;
    }
};
