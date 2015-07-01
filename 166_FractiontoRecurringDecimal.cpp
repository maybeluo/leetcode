// Simulation. When the reminders start to duplicate, then the fraction recur.
// It still takes me three hours to implement the code even AFTER I read the solution.
// My implemention is ugly, because of putting L52-54 before L56, which can't handle condition like 1/6.
// See better solution here: http://blog.csdn.net/u012162613/article/details/41998617

#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include <cmath>
#include <unordered_map>
using namespace std;

typedef long long LL;

template <typename T>
string numberToString(T number){
	ostringstream ss;
	ss<<number;
	return ss.str();
}
template <typename T>
T stringToNumber(string s){
	istringstream ss(s);
	T result;
	return ss>>result ? result: 0;
}

string fractionToDecimal(int numerator, int denominator) {
	LL n = numerator, d = denominator;
	int flag = 0;
	assert(d != 0);
	if(n*d < 0) flag = 1;
	n = abs(n);
	d = abs(d);

	string intPart = numberToString(n/d);
	if(flag) intPart.insert(0, 1, '-');

    n %= d;
	if( n == 0 ){
		return intPart;
	}

	string md = ".";
	int pos = 1;
	unordered_map<LL,int> remindPos;
	unordered_map<LL,LL> remindQuo;
	remindPos.clear();
	remindQuo.clear();
	while(n > 0) {
		n *= 10;
		LL a = n % d; // Reminder
		LL quo = n/d; // Quotient
		unordered_map<LL,int>::iterator im = remindPos.find(a);
		if( im == remindPos.end() || (im != remindPos.end() && remindQuo[a] != quo ) ){
			md += numberToString(quo);
			remindQuo[a] = quo;
			remindPos[a] = pos;
			n %= d;
			pos += 1;
		}
		else{
			int curPos = im->second;
			if(a != 0){ // has Recurring 
				md.insert(curPos, 1, '(');
				md += ')';
			}
			break;
		}
	}
	return intPart + md;
}

int main() {
	int n, d;
	while(cin>>n>>d){
		cout<<fractionToDecimal(n,d)<<endl;
	}
	return 0;
}

