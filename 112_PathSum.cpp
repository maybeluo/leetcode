// See 113.

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
    void dfs(int& freq, TreeNode* nt, int cnt, int sum) {
        if(nt->left == NULL && nt->right == NULL){
            if(cnt + nt->val == sum){
                freq += 1;
            }
            return ;
        }
        if(nt->left != NULL){
            dfs(freq, nt->left, cnt + nt->val, sum);
        }
        if(nt->right != NULL){
            dfs(freq, nt->right, cnt + nt->val, sum);
        }
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        int freq = 0;
        
        if(root == NULL) return freq;

        dfs(freq, root, 0, sum);

        return freq;
    }
};

// version 2.
bool dfs(TreeNode* root, int cnt, int target) {
    if(root == NULL) return false;
    if(root -> left == NULL && root -> right == NULL) {
        if(cnt + root -> val == target) return true;
        else return false;
    }
    return dfs(root -> left, cnt + root -> val, target)
        || dfs(root -> right, cnt + root -> val, target);
}

bool hasPathSum(TreeNode* root, int sum) {
    return dfs(root, 0, sum);
}
