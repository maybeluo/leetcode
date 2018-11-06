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
    void dfs(TreeNode* par, vector<int>& inorder, int il, int ir, vector<int>& postorder, int pl, int pr, int flag) {
        if( il > ir || pl > pr ) return ;
        int val = postorder[pr];
        int pos = -1;
        for(int i = il; i <= ir; i++) {
            if(inorder[i] == val) {
                pos = i;
                break;
            }
        }
        TreeNode *root = new TreeNode(val);
        
        if(!flag)   par -> left = root;
        else    par -> right = root;
        
        int leftNum = pos - il, rightNum = ir - pos;
        if(leftNum > 0) {
            dfs(root, inorder, il, pos - 1, postorder, pl, pr - rightNum -1, 0);
        }
        if(rightNum > 0) {
            dfs(root, inorder, pos + 1, ir, postorder, pr - rightNum, pr - 1, 1);    
        }
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if( inorder.size() < 1 || inorder.size() != postorder.size() ) return NULL;
        TreeNode *par = new TreeNode(0);
        dfs(par, inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, 0);
        TreeNode *root = par -> left;
        par -> left = NULL;
        par -> right = NULL;
        return root;
    }
};
