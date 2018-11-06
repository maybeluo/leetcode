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
    void findNode(TreeNode *root, TreeNode **last, TreeNode **low, TreeNode **up) {
        if(root != NULL) {
            findNode(root -> left, last, low, up);
            if( (*last) != NULL && root -> val <= (*last) -> val ) {
            	if( (*up) == NULL ) *up = *last; // first occurance of reverse order.
            	*low = root;
            }
            (*last) = root;
            findNode(root -> right, last, low, up);
        }
    }
    
    
    void recoverTree(TreeNode* root) {
        if(root == NULL) return ;
        TreeNode *last = NULL, *p = NULL, *q = NULL;
        findNode(root, &last, &p, &q);
        if(p != NULL && q != NULL) swap(p -> val, q -> val);
        return ;
    }
};
