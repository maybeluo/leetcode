// Tarjan offline LCA algorigthm isn't quite suit for this problem when nodes don't have unique integer label...

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || (p == NULL || q == NULL) ) return NULL;
        if(root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        
        if(left != NULL && right != NULL)   return root;
        else if(left != NULL)   return left;
        else if(right != NULL)  return right;
        else return NULL;
    }
};
