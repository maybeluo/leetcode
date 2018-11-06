int largestRectangleArea(vector<int> & height) {
	int n = height.size(), mx = 0;
	int l = -1, r = n, i = 0;
	vector< pair<int, int> > v;
	for(i = 0; i < n; i++) {
		while( !v.empty() && v.back().first > height[i] ) {
			int left = (v.size() > 1) ? v[v.size() - 2].second : l;
			mx = max(mx, (i - left - 1) * v.back().first);
			v.pop_back(); 
		}
		v.push_back( make_pair(height[i], i) );
	}
	while( !v.empty() ){
		int left = (v.size() > 1) ? v[v.size() - 2].second : l;
		mx = max(mx, (r - left - 1)*v.back().first);
		v.pop_back();
	}
	return mx;
}

int maximalRectangle(vector< vector<char> > & matrix) {
	int mx = 0, m = matrix.size();
	if(m < 1) return mx;
	int n = matrix[0].size();
	vector< vector<int> > vv(m);
	for(int i = 0; i < m; i++) {
		vector<int> v(n, 0);
		vv[i] = v;
	}
	for(int i = 0; i < n; i++) vv[0][i] = matrix[0][i] - '0';
	for(int i = 1; i < m; i ++) {
		for(int j = 0; j < n; j++) {
			vv[i][j] = (matrix[i][j] - '0') ? vv[i-1][j] + 1 : 0;
		}
	}
	for(int i = 0; i < m; i++) {
		mx = max(mx, largestRectangleArea(vv[i]) );
	}
	return mx;
}

