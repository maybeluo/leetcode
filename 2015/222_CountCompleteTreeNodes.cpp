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
    int getDepth(TreeNode* root) {
        if(root == NULL) return -1;
        int depth = 0;
        while(root -> left != NULL) {
            depth ++;
            root = root -> left;
        }
        return depth;
    }
    
    int countNodes(TreeNode* root) {
        // max depth, start from 0
        int depth = 0,  ans = 0, r;
        depth = getDepth(root);
        
        TreeNode *p = root;
        while(p != NULL) {
            r = getDepth(p -> right);
            if( r == depth - 1 ) { // left is prefect binary tree
                ans += (1 << depth); // add left subtree and the root
                p = p -> right;
            }
            else { // right is perfect, but with height (depth - 2)
                ans += (1 << (depth-1));// add right subtree and the root
                p = p -> left;
            }
            depth --;
        }
        
        return ans;
    }
};
