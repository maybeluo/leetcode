#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <sstream>
using namespace std;

struct compare {
    bool operator()(const string& first, const string& second) {
        if( first.size() == second.size() ) {
        	return first > second;
        }
        else{
            int i = 0, a = first.size(), b = second.size();
            int len = max(a,b);
            while( i < len ) {
                if(first[i % a] > second[i % b]) return true;
                else if(first[i % a] < second[i % b]) return false;
                else i++;
            }
            // Only one condition can step here: first is a part of second string, or conversely.
            // i.e. first = "ab....c", second = "ab...cab...cab...cab"
            // the value "p" in the following the the reminder of the longer string when remove the recurrent part of shorter string.
            if(a < b) {
            	string t = "";
            	int p = i % a;
            	for(int j = p; j < a; j++ ) t += first[j];
            	for(int j = p - 1; j >= 0; j --) t+= first[j];
            	t += first[0];
            	return t > first;
            }
            else {
            	string t = "";
            	int p = i % b;
            	for(int j = p; j < b; j++ ) t += second[j];
            	for(int j = p - 1; j >= 0; j --) t+= second[j];
            	t += second[0];
            	return t < second;
            }
        }
    }    
};

template <typename T>
string number2String(T num) {
    ostringstream ss;
    ss << num;
    return ss.str();
}

string largestNumber(vector<int>& nums) {
    vector<string> vs;
    vs.clear();
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); it ++) {
    	if(*it > 0) {
    		//cout<<*it<<":"<<number2String(*it)<<";"<<endl;
    		vs.push_back( number2String(*it) );
    	}
    }
    compare cmp;
    sort(vs.begin(), vs.end(), cmp);
    
    string ans = "";
    for(vector<string>::iterator it = vs.begin(); it != vs.end(); it ++) {
        cout<<*it<<endl;
        ans += *it;
    }
    if(ans.size() > 0 && ans[0] == '0') ans = "0";
    
    return ans;
}

int main() {
	// your code goes here
	int n;
	while( scanf("%d", &n) != EOF) {
		vector<int> v(n,0);
		for(int i = 0; i < n; i ++) {
			cin>>v[i];
		}
		cout<<"result: "<<largestNumber(v)<<endl;
	}
	return 0;
}
