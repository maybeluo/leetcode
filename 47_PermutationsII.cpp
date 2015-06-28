// Need to be done.
// The code below is ugly...

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

int cnt = 0;

void dfs(set< vector<int> >& st, vector<int>& v, int pos ) {
    if( pos >= v.size() ) {
        st.insert(v);
        for(int i = 0; i < v.size(); i++){
            printf("%d ", v[i]);
        }
        cnt += 1;
        printf("\n");
        return ;
    }
    int i, j;
    dfs(st, v, pos + 1);

    for(i = pos + 1; i < v.size(); i = j ) {
        for( j = i + 1; j < v.size(); j++)
            if( v[i] != v[j] ) break;
        if( v[i] != v[pos] ) {
            swap(v[i], v[pos]);
            dfs(st, v, pos + 1);
            swap(v[i], v[pos]);
        }
    }
}

vector< vector<int> > permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    set< vector<int> > st;
    st.clear();
    dfs( st, nums, 0 );
    vector< vector<int> > vs;
    vs.clear();
    for(set< vector<int> >::iterator it = st.begin(); it != st.end(); it ++)
        vs.push_back(*it);
    return vs;
}

int main()
{
    int n;
    vector<int> v;
    while( scanf("%d", &n) != EOF){
        v.clear();
        cnt = 0;
        for(int i = 0; i < n; i++){
            int t;
            scanf("%d",&t);
            v.push_back(t);
        }
        printf("\n");
        permuteUnique(v);
        printf("%d\n", cnt);
    }
    return 0;
}
