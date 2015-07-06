// Pre-order: root, left, right
// Use iteration to preorder the tree.

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        ans.clear();
        if(root == NULL) return ans;
        
        vector<TreeNode*> v;
        v.clear();
        TreeNode* cur = root;
        while(cur != NULL || !v.empty() ) {
            while(cur != NULL ) {
                ans.push_back(cur -> val);
                v.push_back(cur);
                cur = cur -> left;
            }
            cur = v.back();
            v.pop_back();
            cur = cur -> right;
        }
        return ans;
    }
};
