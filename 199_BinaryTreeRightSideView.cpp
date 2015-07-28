// version 1.
// get depth first, then control every level output the right most one.
// actually, the size of the result vector is the depth! see version 2.

class Solution {
public:
    int getDepth(TreeNode *root) {
        if(root == NULL) return -1;
        if(root -> left == NULL && root -> right == NULL) return 0;
        if(root -> left != NULL && root ->right != NULL) {
            return 1 + max(getDepth(root -> left), getDepth(root -> right));
        }
        else if(root -> left == NULL) {
            return ( 1 + getDepth(root -> right) );
        }
        else {
            return ( 1 + getDepth(root -> left) );
        }
    }
    
    void dfs(TreeNode* root, int dep, vector<int>& ans, vector<int>& flag) {
        if(root == NULL) return;
        if(!flag[dep]) {// if the level hasn't been viewed before
            ans.push_back(root -> val);
            flag[dep] = 1;
        }
        dfs(root -> right, dep + 1, ans, flag);
        dfs(root -> left, dep + 1, ans, flag);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        ans.clear();
        if(root == NULL) return ans;
        
        int dep = getDepth(root);
        
        vector<int> flag(dep + 10, 0);
        dfs(root, 0, ans, flag);
        
        return ans;
    }
};



// version 2.
// use the size of result vector as depth. 

class Solution {
public:
    void dfs(TreeNode* root, int dep, vector<int>& ans) {
        if(root == NULL) return;
        if(ans.size() < dep) {// if the level hasn't been viewed before
            ans.push_back(root -> val);
        }
        dfs(root -> right, dep + 1, ans);
        dfs(root -> left, dep + 1, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        ans.clear();
        dfs(root, 1, ans);
        return ans;
    }
};
