// Two stack.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        ans.clear();
        if(root == NULL) return ans;
        
        vector<TreeNode*> vroot, vleaf;
        vroot.clear();
        vleaf.clear();
        
        TreeNode* cur = root;
        vroot.push_back(cur);
        while( !vroot.empty() ) {
            cur = vroot.back();
            vroot.pop_back();
            vleaf.push_back(cur);
            
            if( cur -> left != NULL ) vroot.push_back(cur -> left);
            if( cur -> right != NULL ) vroot.push_back(cur -> right);
        }
        
        while( !vleaf.empty() ) {
            cur = vleaf.back();
            vleaf.pop_back();
            ans.push_back(cur -> val);
        }
        
        return ans;
    }
};

// One stack. L65!!
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        ans.clear();
        if(root == NULL) return ans;
        
        vector<TreeNode*> v;
        v.clear();
        
        TreeNode* cur = root;
        do {
            while( cur != NULL ) {
                if(cur -> right != NULL)
                    v.push_back( cur -> right );
                v.push_back(cur);
                cur = cur -> left;
            }
            
            cur = v.back();
            v.pop_back();
            if( cur -> right != NULL && cur -> right == v.back() ) {
                v.pop_back();
                v.push_back( cur );
                cur = cur -> right;
            }
            else{
                ans.push_back(cur -> val);
                cur = NULL;
            }
            
        }while( !v.empty() );
        
        return ans;
    }
};

// version 3.
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> ans;
	stack< pair<TreeNode*, int> > sk;
	sk.push( make_pair(root, 0) );
	while( !sk.empty() ) {
		TreeNode* now = sk.top().first;
		if(now == NULL) {
			sk.pop();
			continue;
		}
		switch( sk.top().second ++ ) {
		case 0:
			sk.push( make_pair(now -> left, 0) );
			break;
		case 1:
			sk.push( make_pair(now -> right, 0) );
			break;
		case 2:
			TreeNode* q = sk.top();
			sk.pop();
			ans.push_back(q -> val);
		}
	}
	return ans;
}
