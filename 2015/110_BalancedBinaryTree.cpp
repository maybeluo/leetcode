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
    bool dfs(TreeNode* p, int& dep) {
        if(p == NULL) {
            dep = 0;
            return true;
        }
        int l = 0, r = 0;
        if(dfs(p->left, l) && dfs(p->right, r) ) {
            if( abs(l - r) > 1 ) return false;
            dep = 1 + max(l, r);
            return true;
        }
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int dep = 0;
        if( dfs(root, dep) ) return true;
        else return false;
    }
};
