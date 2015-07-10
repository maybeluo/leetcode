// recursive

#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;

LL dfs(LL m, LL base) {
  if( m < 1) return 0;
  if( m <= 9 ) {
    return 1;
  }
  LL ans = 0;
  if( m/base >= 1 ) { // base my bigger than m! eg. 1011/1000
    if(m/base > 1)
      ans += base;
    else
      ans += (m%base + 1);
  }
  
  ans += (m/base) * dfs(base - 1, base / 10); // 0 ~ (base-1), eg. 0-99
  ans += dfs(m%base, base/10); // reminder
  
  return ans;
}

int countDigitOne(int n) {
  LL ans = 0, m = n;
  LL base = 1;
  while(base <= m) {
    base *= 10;
  }
  base /= 10;
  return dfs(m, base);
  
}
    
int main() {
  // your code goes here
  int n;
  while(cin>>n) {
    cout<<"input:"<<n<<"    output:"<<countDigitOne(n)<<endl;
  }
  return 0;
}
