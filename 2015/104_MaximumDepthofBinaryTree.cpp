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
        if(root == NULL) {
            mx = max(mx, dep);
            return ;
        }
        dfs(root->left, mx, dep + 1);
        dfs(root->right, mx, dep + 1);
    }
    
    int maxDepth(TreeNode* root) {
        int mx = 0;
        dfs(root, mx, 0);
        return mx;
    }
};

// version 2.
int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    return 1 + max( maxDepth(root -> left) , maxDepth(root -> right) );
}

// version 3.
int maxDepth(TreeNode* root) {
    int depth = 0;
    stack<pair<TreeNode*, int>> myStack;
    myStack.push( make_pair(root, 0) );
    
    while( !myStack.empty() ) {
        pair<TreeNode*, int> p = myStack.top();
        myStack.pop();
        if(p.first == NULL) depth = max(depth, p.second);
        else {
            myStack.push( make_pair(p.first -> left, p.second + 1) );
            myStack.push( make_pair(p.first -> right, p.second + 1) );
        }
    }
    
    return depth;
}

