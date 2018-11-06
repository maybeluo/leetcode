 // version 3. use POINTer to pointer to record the last data. L17, L4. L7 "(*last)", the "()" is necessary.
 class Solution {
public:
    bool isBST(TreeNode* root, TreeNode** last) {
        if(root != NULL) {
            if( !isBST(root -> left, last) )    return false;
            if( (*last) != NULL && (*last) -> val >= root -> val)  return false;
            (*last) = root;
            return isBST(root -> right, last);
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        return isBST(root, &pre);
    }
};

// version 2.
class Solution {
public:
    bool isBST(TreeNode* root, TreeNode* low, TreeNode* up) {
        if(root != NULL) {
            if( (low != NULL && root -> val <= low -> val) || (up != NULL && root -> val >= up -> val) )
                return false;
            return isBST(root -> left, low, root) && isBST(root -> right, root, up);
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        return isBST(root, NULL, NULL);
    }
};
 
// version 1. use O(n) to record the inorder result.
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& v) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            v.push_back(root->val);
            return;
        }
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        v.clear();
        
        dfs(root, v);
        
        for(int i = 1; i < v.size(); i++) {
            if(v[i] <= v[i-1]) return false;
        }
        return true;
    }
};
