  // BFS version.
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  	queue<TreeNode*> q;
  	while( !q.empty() ) q.pop();
  	vector< vector<int> > vv;
  	vv.clear();
  	if(root == NULL) return vv;
  	q.push(root);
  	while( !q.empty() ) {
  		int n = q.size();
  		vector<int> v;
  		v.clear();
  		for(int i = 0; i < n; i ++) {
  			TreeNode* p = q.front();
  			q.pop();
  			v.push_back( p -> val );
  			if(p -> left) q.push(p -> left);
  			if(p -> right) q.push(p -> right);
  		}
  		vv.push_back(v);
  	}
  	for(int i = 0; i < vv.size(); i++) {
  	    if(i%2) reverse(vv[i].begin(), vv[i].end());
  	}
  	return vv;
  }
