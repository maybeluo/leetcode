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
    bool dfs(TreeNode* p, TreeNode* q) {
        if( p == NULL && q == NULL ) {
            return true;
        }
        if( (p == NULL && q != NULL) || (p != NULL && q == NULL) ) {
            return false;
        }
        int left = p -> val, right = q -> val;
        if(left != right) return false;
        else{
            return dfs(p->left, q->right) && dfs(p->right, q->left);
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        int flag = 1;
        if( root == NULL || (root ->left == NULL && root ->right == NULL ) ) {
            return true;
        }
        
        return dfs(root->left, root->right);
    }
};
