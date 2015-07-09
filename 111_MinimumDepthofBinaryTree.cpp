// Leaf – a node with no children.
// Thus, a tree like "[1,2]", "1" has no right child, but it's not a leaf. 

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
        if(root -> left == NULL && root -> right == NULL) {
            mx = min(mx, dep);
            return ;
        }
        if(root -> left != NULL) dfs(root->left, mx, dep + 1);
        if(root -> right != NULL) dfs(root->right, mx, dep + 1);
    }
    
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int mx = 0x5fffffff;
        dfs(root, mx, 1);

        return mx;
    }

};
