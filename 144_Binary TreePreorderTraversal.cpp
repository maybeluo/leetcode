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
 // a neat version
 vector<int> preorderTraversal(TreeNode* root) {
	vector<int> ans;
	stack<TreeNode*> sk;
	sk.push(root);
	while( !sk.empty() ) {
		TreeNode *p = sk.top();
		sk.pop();
		if(p == NULL) continue;
		ans.push_back(p -> val);
		sk.push(p -> right);
		sk.push(p -> left); 
	}
	return ans;
}
 
 // an ugly version
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
