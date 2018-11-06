/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while( !nodeStack.empty() ) nodeStack.pop();
        while(root != NULL) {
            nodeStack.push(root);
            root = root -> left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodeStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* now = nodeStack.top();
        nodeStack.pop();
        if(now->right != NULL) {
            TreeNode *cur = now -> right;
            while(cur != NULL) {
                nodeStack.push(cur);
                cur = cur -> left;
            }
        }
        return now -> val;
    }
private:
    stack<TreeNode*> nodeStack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
