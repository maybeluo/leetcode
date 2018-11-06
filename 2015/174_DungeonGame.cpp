#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

bool isReachable(vector<vector<int>>& dungeon, int m, int n, int val) {
	int health[m + 10][n + 10];
	memset(health, 0, (m + 10)*(n + 10)*sizeof(int));
	
	int t = val + dungeon[0][0];
	if(t < 1) {
		return false;
	}
	else{
		health[0][0] = t;
	}
	
	for(int i = 1; i < m; i++) {
		if(health[i-1][0] <= 0)
			health[i][0] = -1;
		else
			health[i][0] = health[i-1][0] + dungeon[i][0];
	}
	for(int i = 1; i < n; i++) {
		if(health[0][i-1] <= 0)
			health[0][i] = -1;
		else
			health[0][i] = health[0][i-1] + dungeon[0][i];
	}
	
	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			if( health[i][j-1] <= 0 && health[i-1][j] <= 0) {
				health[i][j] = -1;
			}
			else if( health[i][j-1] > 0 && health[i-1][j] > 0 ){
				health[i][j] = ( max(health[i][j-1], health[i-1][j]) + dungeon[i][j] );
			}
			else if( health[i][j-1] > 0 ) {
				health[i][j] = health[i][j-1] + dungeon[i][j];
			}
			else {
				health[i][j] = health[i-1][j] + dungeon[i][j];
			}
		}
	}
	
	if(health[m-1][n-1] > 0) return true;
	else return false;
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
	int m = dungeon.size();
	if(m < 1) return 0;
	int n = dungeon[0].size();
	if(n < 1) return 0;
	long long l = 1, r = 100;
	while(l < r) {
		long long mid = (l + r) >> 1;
		printf("l:%lld   r:%lld   mid:%lld\n", l, r, mid);
		if( isReachable(dungeon, m, n, mid) ) {
			r = mid;
		}
		else l = mid + 1;
	}
	return r;
}

int main() {
	// your code goes here
	int m, n;
	while( scanf("%d %d", &m, &n) != EOF ){
		vector<vector<int>> vv;
		vv.clear();
		for(int i = 0; i < m; i++) {
			vector<int> v(n,0);
			vv.push_back(v);
		}
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%d",&vv[i][j]);
			}
		}
		printf("here\n");
		printf("%d\n", calculateMinimumHP(vv));
	}
	return 0;
}
