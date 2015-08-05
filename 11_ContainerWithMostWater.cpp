// version 1.
int maxArea( vector<int>& height) {
    int n = height.size(), mx = -1;
    int l = 0, r = n - 1, i = 0, j = 0;
    while(l < r) {
        mx = max(mx, (r - l) * min(height[l], height[r]) );
        if( height[l] < height[r] ) l++;
        else if(height[l] > height[r]) r--;
        else l++, r--;
    }
    return mx;
}

// version 2.
int maxArea( vector<int>& height) {
	int n = height.size(), mx = -1;
	int l = 0, r = n - 1, i = 0, j = 0;
	while(l < r) {
		mx = max(mx, (r - l) * min(height[l], height[r]) );
		if( height[l] < height[r] ) {
			i = l + 1;
			while(i < r && height[i] <= height[l] ) i ++;
			l = i;
		}
		else if(height[l] > height[r]) {
			i = r - 1;
			while(i > l && height[i] <= height[r]) i --;
			r = i;
		}
		else {
			i = 1;
			while( l + i < r - i && height[l + i] == height[r - i]) {
				if(height[l + i] > height[l]) break;
				i ++;
			}
			l += i, r -= i;
		}
	}
	return mx;
}
