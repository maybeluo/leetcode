// use QUEUE, not stack, to BFS.
// use L35-L41 TLE because the dict may be very large.

class Node {
public:
	string s;
	int l;
	Node(string _s, int _l) {
		s = _s;
		l = _l;
	}
	Node(){}
};

class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        wordDict.insert(endWord);
        queue<Node> myQueue;
        Node nt(beginWord, 1);
        myQueue.push(nt);
        
        unordered_set<string> st;
        st.insert(beginWord);
        
        while(!myQueue.empty()) {
        	nt = myQueue.front();
        	myQueue.pop();
        	if( nt.s == endWord ) {
        		return nt.l;
        	}
        	
        	/*
        	for(unordered_set<string>::iterator it = wordDict.begin(); it != wordDict.end(); it++) {
                if( st.find(*it) == st.end() && differByOne(*it, nt.s) ) {
                    Node tmp(*it, nt.l + 1);
	        		myQueue.push(tmp);
	        		st.insert(*it);
                }
        	}
        	*/
        	
        	for(int i = 0; i < nt.s.size(); i++) {
        	    string t = nt.s;
        		for(int j = 0; j < 26; j++) {
        			t[i] = (j + 'a');
        			if( wordDict.find(t) != wordDict.end() && st.find(t) == st.end() ) {
	        			Node tmp(t, nt.l + 1);
	        			myQueue.push(tmp);
	        			st.insert(t);
	        		}
        		}
        	}
        }
        return 0;
    }
};
