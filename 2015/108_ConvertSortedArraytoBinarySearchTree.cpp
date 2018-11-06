//TLE: L8 & L16

class Solution {
public:
    TreeNode* dfs(vector<int>& nums, int l, int r) {
        if(l > r) return NULL;
        if(l == r) {
            // TreeNode* p;
            TreeNode* p = (TreeNode*) malloc( sizeof(TreeNode) );
            p -> val = nums[l];
            p -> left = NULL;
            p -> right = NULL;
            return p;
        }
        int mid = (l + r)/2;
        // TreeNode* root;
        TreeNode* root = (TreeNode*) malloc( sizeof(TreeNode) );
        root -> val = nums[mid];
        root->left = dfs(nums, l, mid - 1);
        root->right = dfs(nums, mid + 1, r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = dfs(nums, 0, n-1);
        return root;
    }
};


// To be debugged.
class Solution {
public:
    void dfs(TreeNode** root, vector<int>& nums, int l, int r) {
        if(l > r) {
            (*root) = NULL;
            return;
        }
        if(l == r) {
            // TreeNode* p;
            (*root) = (TreeNode*) malloc( sizeof(TreeNode) );
            (*root) -> val = nums[l];
            (*root) -> left = NULL;
            (*root) -> right = NULL;
            return ;
        }
        int mid = (l + r)/2;
        // TreeNode* root;
        (*root) = (TreeNode*) malloc( sizeof(TreeNode) );
        (*root) -> val = nums[mid];
        dfs( &(*root)->left, nums, l, mid - 1 );
        dfs( &(*root)->right, nums, mid + 1, r );
        return ;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n < 1) return NULL;
        TreeNode** p;
        dfs(p, nums, 0, n-1);
        return *p;
    }
};
