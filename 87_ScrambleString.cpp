// The tags "DP" given by leetcode mislead me...
// Memorization is slower than no-memory...

//version 1. with memorization
const int maxAlaphbet = 26;

class Solution {
public:
	bool isAnagram(const string& a, const string& b) {
		int n = a.size();
    	if( n != b.size() ) return false;
    	int flag[maxAlaphbet];
    	memset(flag, 0, maxAlaphbet * sizeof(int) );
    	
        for(int i = 0; i < n; i++) {
        	flag[ a[i] - 'a' ] ++;
        	flag[ b[i] - 'a' ] --;
        }
        
        for(int i = 0; i < maxAlaphbet; i++) {
        	if(flag[i] != 0) return false;
        }
        return true;
	}
	
	bool scrambleHelper(string a, string b, unordered_map<string, string>& tmap, unordered_map<string, string>& fmap) {
		if( ! isAnagram(a, b) ) {
			fmap[a] = b;
			return false;
		}
		if(a == b) {
			tmap[a] = b;
			return true;
		}
		int n = a.size();
		for(int i = 1; i < n; i++) {
			string a0 = a.substr(0, i), a1 = a.substr(i, n - i), b0 = b.substr(0, i), b1 = b.substr(i, n - i);
			if( tmap[a0] == b0 && tmap[a1] == b1 ) return true;
			if( (fmap[a0] != b0 && fmap[a1] != b1) && 
				( scrambleHelper(a0, b0, tmap, fmap) && scrambleHelper(a1, b1, tmap, fmap) ) )
				return true;
			
			a0 = a.substr(0, i), a1 = a.substr(i, n - i), b0 = b.substr(0, n - i), b1 = b.substr(n - i, i);
			if( tmap[a0] == b1 && tmap[a1] == b0 ) return true;
			if( (fmap[a0] != b1 && fmap[a1] != b0) && 
				( scrambleHelper(a0, b1, tmap, fmap) && scrambleHelper(a1, b0, tmap, fmap) ) )
				return true;
		}
		return false;
	}
 	
    bool isScramble(string s1, string s2) {
    	int n = s1.size();
    	if(n != s2.size() ) return false;
    	
    	unordered_map<string, string> tmap, fmap;
    	tmap.clear();
    	fmap.clear();
    	
    	return scrambleHelper(s1, s2, tmap, fmap);
    }
};

// version 2.
const int maxAlaphbet = 26;

class Solution {
public:
	
	bool scrambleHelper(string a, string b) {
	    if(a == b) return true;
		int n = a.size();
    	if( n != b.size() ) return false;
    	int flag[maxAlaphbet] = {0};
    	
        for(int i = 0; i < n; i++) {
        	flag[ a[i] - 'a' ] ++;
        	flag[ b[i] - 'a' ] --;
        }
        
        for(int i = 0; i < maxAlaphbet; i++) {
        	if(flag[i] != 0) return false;
        }
        
		for(int i = 1; i < n; i++) {
			if( scrambleHelper( a.substr(0, i), b.substr(0, i) ) && scrambleHelper( a.substr(i), b.substr(i) ) )
				return true;
			if( scrambleHelper( a.substr(0, i), b.substr(n - i) ) && scrambleHelper( a.substr(i), b.substr(0, n - i) ) )
				return true;
		}
		return false;
	}
 	
    bool isScramble(string s1, string s2) {
    	int n = s1.size();
    	if(n != s2.size() ) return false;
    	
    	return scrambleHelper(s1, s2);
    }
};
