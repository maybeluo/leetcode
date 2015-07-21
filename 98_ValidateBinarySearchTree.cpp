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
    void dfs(TreeNode* root, vector<int>& v) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            v.push_back(root->val);
            return;
        }
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        v.clear();
        
        dfs(root, v);
        
        for(int i = 1; i < v.size(); i++) {
            if(v[i] <= v[i-1]) return false;
        }
        return true;
    }
};
