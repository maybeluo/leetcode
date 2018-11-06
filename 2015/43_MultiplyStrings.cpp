// 1A. L88-91 to remove the leading '0'.

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

template <typename T>
string numberToString( T number ) {
	ostringstream ss;
	ss << number;
	return ss.str();
}

template <typename T>
T stringToNumber( string s ) {
	istringstream ss(s);
	T result;
	return ss >> result ? result : 0;
}

// Add to string
string add(string s1, string s2) {
	int n1 = s1.size(), n2 = s2.size();
	if(n1 < 1) return s2;
	if(n2 < 1) return s1;
	int carry = 0;
	int l = n1-1, r = n2 - 1;
	string ans = "";
	while( l >= 0 && r >= 0 ) {
		int nb = carry + stringToNumber<int>( s1.substr(l,1) ) +  stringToNumber<int>( s2.substr(r,1) );
		ans += (nb%10 + '0');
		carry = nb/10;
		l --;
		r --;
	}
	while(l >= 0){
		int nb = carry + stringToNumber<int>( s1.substr(l,1) );
		ans += (nb%10 + '0');
		carry = nb/10;
		l --;
	}
	while(r >= 0){
		int nb = carry + stringToNumber<int>( s2.substr(r,1) );
		ans += (nb%10 + '0');
		carry = nb/10;
		r --;
	}
	if(carry != 0 ) ans += (carry + '0');
	reverse(ans.begin(), ans.end());
	return ans;
}

// string multiply
string multiply(string num1, string num2) {
	string ans = "";
	int n1 = num1.size(), n2 = num2.size();
	if( n1 < 1 || n2 < 1) return ans;
	for(int i = 0; i < n1; i++){
		if(num1[i] > '9' || num1[i] < '0' ) return ans;
	}
	for(int i = 0; i < n2; i++){
		if(num2[i] > '9' || num2[i] < '0' ) return ans;
	}

	string pre = "";
	int carry = 0;
	int pos = n1 - 1;
	while(pos >= 0) {
		int c1 = stringToNumber<int>( num1.substr(pos,1) );
		string smp = "";
		carry = 0;
		for(int i = n2 - 1; i >= 0; i--){
			int c2 = stringToNumber<int>( num2.substr(i,1) );
			int res = c1 * c2 + carry;
			smp += (res%10 + '0');
			carry = res / 10;
		}
		if(carry > 0) smp+= (carry + '0');
		reverse(smp.begin(), smp.end());
		for(int i = n1 - 1; i > pos; i--)
			smp += '0';
		pre = add(pre, smp);
		pos --;
	}
	int nz, np = pre.size();
	for(nz = 0; nz < np - 1; nz++){
		if( pre[nz] != '0' ) break; 
	}
	pre = pre.substr(nz, np-nz); // remove leading '0'
	return pre;
}

int main() {
	string a, b;
	while(cin>>a>>b) {
		cout<<"a: "<<a<<"    b: " << b << endl;
		cout<<"\tadd: "<<add(a,b)<<endl;
		cout<<"\tmultiply: "<<multiply(a, b)<<endl;
	}
	return 0;
}
