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
    TreeNode* dfs(TreeNode *root) {
        if(root -> left == NULL && root -> right == NULL) {
            return root;
        }
        
        if(root -> left != NULL){
            
            TreeNode *pLeft = root -> left;
            TreeNode *pRight = root -> right;
            
            // left child to right
            root -> right = pLeft;
            root -> left = NULL;
            
            TreeNode* r = dfs(pLeft);
            r -> right = pRight;// left child pointer to right
            
            if(pRight != NULL) {
                return dfs(pRight);
            }
            else 
                return r;
        }
        else {
            if(root -> right != NULL)
                return dfs(root -> right);
            else
                return NULL;
        }
    }
    
    void flatten(TreeNode* root) {
        if(root == NULL) return ;
        TreeNode *p = root;
        dfs(p);
        return ;
    }
};
