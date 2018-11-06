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

// version 2
int minDepth(TreeNode* root) {
    if(root == NULL) return 0;
    if(root -> left == NULL && root -> right == NULL) return 1;
    else if(root->left == NULL) return 1 + minDepth(root -> right);
    else if(root->right == NULL) return 1 + minDepth(root -> left);
    else return 1 + min(minDepth(root -> left), minDepth(root -> right));
}

// version 3
int minDepth(TreeNode* root) {
    int depth = 0x3fffffff;
    stack<pair<TreeNode*, int>> s;
    s.push( make_pair(root, 1) );
    while( !s.empty() ) {
        pair<TreeNode*, int> p = s.top();
        s.pop();
        if(p.first == NULL) continue;
        if(p.first -> left == NULL && p.first -> right == NULL) depth = min(depth, p.second);
        else {
            s.push( make_pair(p.first -> left, p.second + 1) );
            s.push( make_pair(p.first -> right, p.second + 1) );
        }
    }
    if(depth >= 0x3fffffff) return 0;
    return depth;
}
