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
    void dfs(int& freq, vector<int> vt, TreeNode* nt, int cnt, int sum) {
        if(nt->left == NULL && nt->right == NULL){
            if(cnt + nt->val == sum){
                freq += 1;
            }
            return ;
        }
        vt.push_back(nt->val);
        if(nt->left != NULL){
            dfs(freq, vt, nt->left, cnt + nt->val, sum);
        }
        if(nt->right != NULL){
            dfs(freq, vt, nt->right, cnt + nt->val, sum);
        }
        vt.pop_back();
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        int freq = 0;
        
        if(root == NULL) return freq;
        
        vector<int> vt;
        vt.clear();
        dfs(freq, vt, root, 0, sum);

        return freq;
    }
};
