// Must use L37 & L38 instead of L23 & L24. Deepcopy.
// Practice more.

class Solution {
public:
  vector<TreeNode*> dfs(int l, int r) {
    if(l >= r) {
      vector<TreeNode*> v;
      v.clear();
      TreeNode *p = NULL;
      if(l == r) {
        p = (TreeNode*) malloc( sizeof(TreeNode) );
        p -> val = l;
        p -> left = NULL;
        p -> right = NULL;
      }
      v.push_back(p);
      return v;
    }
    vector<TreeNode*> ans;
    ans.clear();
    for(int k = l; k <= r; k++) {
      //TreeNode *root = (TreeNode*) malloc( sizeof(TreeNode) );
      //root -> val = k;
      
      // subtree consists of [k-1, l]
      vector<TreeNode*> leftVec = dfs(l, k-1);
      
      // subtree consists of [k+1, r]
      vector<TreeNode*> rightVec = dfs(k+1, r);
      
      //merge tree
      int leftLen = leftVec.size(), rightLen = rightVec.size();
      for(int i = 0; i < leftLen; i++) {
        for(int j = 0; j < rightLen; j++) {
          // use k as root
          TreeNode *root = (TreeNode*) malloc( sizeof(TreeNode) );
          root -> val = k;
          // merge subtree
          root -> left = leftVec[i];
          root -> right = rightVec[j];
          ans.push_back(root);
        }
      }
    }
    return ans;
  }
  
  vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode* > v;
    v.clear();
    v = dfs(1, n);
    cout<<v.size()<<endl;
    return v;
  }
};
