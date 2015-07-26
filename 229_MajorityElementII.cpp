// There are at most two elements that possibly have.
// swap min first, then max.

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> v;
    v.clear();
    
    int a = 0, b = 0, c = 0;
    int ca = 0, cb = 0, cc = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(cc > cb) { // c is min
            swap(b, c);
            swap(cb, cc);
        }
        if(cb > ca) { // a is max
            swap(a, b);
            swap(ca, cb);
        }
        
        if( nums[i] == a )	ca ++;
        else if(nums[i] == b)	cb ++;
        else if(nums[i] == c)	cc ++;
        else {
            if(ca < 1) {
                a = nums[i];
                ca ++;
            }
            else if(cb < 1) {
                b = nums[i];
                cb ++;
            }
            else {
                c = nums[i];
                cc ++;
            }
        }
    }
    if(cc > cb) { // c is min
        swap(b, c);
        swap(cb, cc);
    }
    if(cb > ca) { // a is max
        swap(a, b);
        swap(ca, cb);
    }
    
    printf("a:%d b:%d c:%d \nca:%d cb:%d cc:%d\n", a, b, c, ca, cb, cc);
    
    int cnt = 0;
    if(ca > 0) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == a) cnt ++;
        }
        if(cnt > nums.size()/3) v.push_back(a);
    }
    
    if(cb > 0) {
        cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == b) cnt ++;
        }
        if(cnt > nums.size()/3) v.push_back(b);
    }
    
    return v;
}

int main() {
	int n;
	while( scanf("%d", &n) != EOF ) {
		vector<int> v(n);
		for(int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		vector<int> ans = majorityElement(v);
		
		printf("res:");
		for(int i = 0; i < ans.size(); i++)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}
