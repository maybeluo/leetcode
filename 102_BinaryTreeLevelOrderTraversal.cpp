// Note the output order.
// Use for in L33, not pop_back().

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> vpre, vaft;
        vpre.clear();
        vaft.clear();
        
        vector<int> vt;
        vector< vector<int> > vv;
        vt.clear();
        vv.clear();
        
        if(root == NULL) return vv;
        
        vpre.push_back(root);
        
        while(1) {
            
            vaft.clear();
            vt.clear();
            
            for(vector<TreeNode*>::iterator it = vpre.begin(); it != vpre.end(); it ++) {
                TreeNode* cur = *it;
                vt.push_back(cur -> val);
                if(cur -> left != NULL) vaft.push_back(cur -> left);
                if(cur -> right != NULL) vaft.push_back(cur -> right);
            }
            vv.push_back(vt);
            
            if( vaft.empty() ) break;
            
            vpre.assign(vaft.begin(), vaft.end());
            
        }
        return vv;
    }
};
