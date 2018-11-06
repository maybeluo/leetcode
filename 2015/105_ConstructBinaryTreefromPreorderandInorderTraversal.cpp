// Key: get the boundry of postorder/preorder by calculate the number of elments in left/right sub-tree.

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
    void dfs(TreeNode* parNode, vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir, int flag){
        if(pl > pr || il > ir) return ;
        
        int val = preorder[pl]; // root value
        int pos = -1;
        for(int i = il; i <= ir; i++) {
            if(inorder[i] == val) {
                pos = i;
                break;
            }
        }
        
        TreeNode *root = new TreeNode(val);
        
        if( !flag ) parNode -> left = root;
        else parNode -> right = root;
        
        int leftNum = pos - il, rightNum = ir - pos;
        if(leftNum > 0) {// left sub-tree is not null
            dfs(root, preorder, pl + 1, pl + leftNum, inorder, il, pos - 1, 0);
        }
        
        if(rightNum > 0) { // right sub-tree is not null
            dfs(root, preorder, pl + 1 + leftNum, pr, inorder, pos + 1, ir, 1);
        }
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() < 1 || preorder.size() != inorder.size()) return NULL;
        
        TreeNode *par = new TreeNode(0);
        dfs(par, preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, 0);
        
        TreeNode *root = par -> left;
        par ->left = NULL;
        par -> left = NULL;
        
        return root;
    }
};
