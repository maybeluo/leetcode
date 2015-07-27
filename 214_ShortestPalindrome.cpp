// reverse the string, then KMP.
// I thought of using either of them independently, but donot realize to connect them together. pity....

void getNext(string s, vector<int>& next) {
  next[0] = -1;
  int n = s.size(), i = 0, p = -1;
  while(i < n - 1) {
    if(p == -1 || s[i] == s[p]) {
      p ++;
      i ++;
      if(s[p] == s[i]) {
        next[i] = next[p];
      }
      else{
        next[i] = p;
      }
    }
    else {
      p = next[p];
    }
  }
}
  
string shortestPalindrome(string s) {
  int n = s.size();
  if(n < 1) return s;
  vector<int> vNext(n, 0);
  // take s as the pattern sequence
  string pattern = s;
  getNext(pattern, vNext);
  
  // reverse s as the text to be matched
  reverse(s.begin(), s.end());
  string text = s;
  
  int i = 0, j = 0;
  while( i < n && j < n ) {
    if(j == -1 || text[i] == pattern[j]) {
      i ++;
      j ++;
    }
    else {
      j = vNext[j];
    }
  }
  
  string ans = text.substr(0, i - j);
  ans += pattern;
  
  return ans;
}
