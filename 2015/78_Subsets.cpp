// Brute force: use <bitset> to enumerate.

#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100;

void dfs(vector< vector<int> >& vv, vector<int>& nums, bitset<MAXN>& bt, int n, int pos) {
    if(pos >= n ){
        string ans = bt.to_string();
        vector<int> vt;
        vt.clear();
        for(int i = 0; i < n; i++) {
            if(ans[i] == '1') {
                vt.push_back(nums[i]);
                cout<<nums[i]<<" ";
            }
        }
        cout<<endl;
        vv.push_back(vt);
        return ;
    }
    bt.flip(MAXN - pos - 1);
    dfs(vv, nums, bt, n, pos + 1);
    bt.flip(MAXN - pos - 1);
    dfs(vv, nums, bt, n, pos + 1);
}

vector< vector<int> > subsets(vector<int>& nums) {
    vector< vector<int> > vv;
    vv.clear();
    int n = nums.size();
    if(n < 1) return vv;

    sort(nums.begin(), nums.end());
    int i = 0, j = 0;
    for(i = 1; i < n; i++) {
        if(nums[i] != nums[j]) {
            j ++;
            nums[j] = nums[i];
        }
    }
    int nu = j + 1;
    cout<<nu<<endl;
    bitset<MAXN> bt;
    bt.reset();
    dfs(vv, nums, bt, nu, 0);
    return vv;
}

int main()
{
    int n;
    while(cin>>n){
        int t;
        vector<int> v;
        v.clear();
        for(int i = 0; i < n; i++){
            cin>> t;
            v.push_back(t);
        }
        subsets(v);
    }
    return 0;
}

// use string instead of bitset
void dfs(vector< vector<int> >& vv, vector<int>& nums, string s, int pos) {
	if(pos == nums.size() ) {
		vector<int> vt;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '1') vt.push_back(nums[i]);
		}
		vv.push_back(vt);
		return ;
	}
	dfs(vv, nums, s, pos + 1);
	s[pos] = '1';
	dfs(vv, nums, s, pos + 1);
	s[pos] = '0';
}

vector< vector<int> > subsets( vector<int>& nums ) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	string s(n, '0');
	vector< vector<int> > vv;
	dfs(vv, nums, s, 0);
	return vv;
}
