// Greedy: start from the min value, assign candy one by one from small to large

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct node {
    int p; // position
    int val; //value
    node(int _p, int _val) {
        p = _p;
        val = _val;
    }
    
    friend bool operator<(const node& a, const node& b) {
        return ( (a.val < b.val ) || (a.val == b.val  &&  a.p < b.p) ); 
    }
    
}Node;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    if(n < 1) return 0;
    
    vector<Node> v;
    v.clear();
    vector<int> vcan(n);
    for(int i = 0; i < n; i++) {
        Node t(i, ratings[i]);
        v.push_back(t);
        vcan[i] = 0x5fffffff;
    }
    sort(v.begin(), v.end());
    
    vcan[ v[0].p ] = 1;
    for(int i = 1; i < n; i++) {
        int l = v[i].p - 1, r = v[i].p + 1, m = v[i].p;
        if( l >= 0 && r < n ) {
        	if(ratings[m] <= ratings[l] && ratings[m] <= ratings[r]) { // m is local min
        		vcan[m] = 1;
        	}
        	else if(ratings[m] > ratings[l] && ratings[m] > ratings[r]) { // m is local max
        		vcan[m] = max(vcan[l], vcan[r]) + 1;
        	}
        	else if(ratings[m] > ratings[l] && ratings[m] <= ratings[r]){
        		vcan[m] = vcan[l] + 1;
        	}
        	else {
        		vcan[m] = vcan[r] + 1;
        	}
        }
        if(l < 0) { // m == 0
        	if(ratings[m] <= ratings[r] ) vcan[m] = 1;
        	else vcan[m] = vcan[r] + 1;
        }
        if(r >= n) { // m == n-1
        	if(ratings[m] <= ratings[l] ) vcan[m] = 1;
        	else vcan[m] = vcan[l] + 1;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
    	printf("%d:%d ", i, vcan[i]);
        ans += vcan[i];
    }
    printf("\n");
    
    return ans;
}
    
    
int main() {
	int n;
	while( scanf("%d", &n) != EOF ) {
		vector<int> v(n, 0);
		for(int i = 0; i < n; i ++) {
			scanf("%d",&v[i]);
		}
		printf("%d\n", candy(v) );
	}
	return 0;
}
