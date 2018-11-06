// use the property of BST, thus not a typical problem LCA.

// version 1. recurisive version
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( (p == NULL || q == NULL) || root == NULL )  return NULL;
        
        if(p -> val > q -> val) swap(p, q); // p pointer to small value
        
        if(p -> val == q -> val) return p; // same node
        
        if(p -> val < root -> val && q -> val < root -> val){ // both p and q are left
            return lowestCommonAncestor(root -> left, p, q);
        }
        else if(p -> val > root -> val && q -> val > root -> val){ // both right
            return lowestCommonAncestor(root -> right, p, q);
        }
        else { // 1. p left, q right  2. one of p and q are root
            return root;
        }
        
    }
};

// version. non-recurisive 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( (p == NULL || q == NULL) || root == NULL )  return NULL;
        
        if(p -> val > q -> val) swap(p, q); // p pointer to small value
        
        if(p -> val == q -> val) return p; // same node
        while(root != NULL) {
            if(p -> val < root -> val && q -> val < root -> val){ // both p and q are left
                root = root -> left;
            }
            else if(p -> val > root -> val && q -> val > root -> val){ // both right
                root = root -> right;
            }
            else { // 1. p left, q right  2. one of p and q are root
                return root;
            }
        }
    }
};
