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
    template<typename T>
    string numberToString(T number) {
        ostringstream ss;
        ss << number;
        return ss.str();
    }
    
    void dfs(vector<string>& res, string s, TreeNode* root) {
        if(root == NULL) return ;
        string st = ( (s.size() < 1) ? "" : (s + "->") );
        st += numberToString(root -> val);
        if(root -> left == NULL && root -> right == NULL) {
            res.push_back(st);
            return ;
        }
        dfs(res, st, root -> left);
        dfs(res, st, root -> right);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        ans.clear();
        dfs(ans, "", root);
        return ans;
    }
};
