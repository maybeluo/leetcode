// Trie + DFS.

const int maxAlphabet = 26;

int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, -1, 0, 1};

class TrieNode {
public:
	bool isWord;
	TrieNode *childrenNode[maxAlphabet];
	TrieNode() {
		isWord = false;
		for(int i = 0; i < maxAlphabet; i++)
			childrenNode[i] = NULL;
	}
};

class Trie {
private:
	TrieNode *root;
public:
	Trie() {
		root = new TrieNode();
	}
	
	TrieNode *getRootNode() {
		return root;
	}
	
	void addWord(string word) {
		TrieNode *p = root;
		for(int i = 0; i < word.size(); i++) {
			if( p -> childrenNode[ word[i] - 'a' ] == NULL )
				p -> childrenNode[ word[i] - 'a' ] = new TrieNode();
			p = p -> childrenNode[ word[i] - 'a' ];
		}
		p -> isWord = true;
	}
};

class Solution {
public:
    Trie myTrie; //= new Trie();
    
    bool isValidIndex(vector<vector<char>>& board, int x, int y) {
    	if( (x >= 0 && x < board.size()) && (y >= 0 && y < board[0].size()) )
    		return true;
    	return false;
    }
    
    void dfs(vector<vector<char>>& board, int r, int c, string& curStr, unordered_set<string>& resSet, TrieNode *root) {
    	if(root -> isWord) {
    		resSet.insert(curStr);
    	}
    	for(int i = 0; i < 4; i++) {
    		int x = r + dirx[i], y = c + diry[i];
    		if( isValidIndex(board, x, y) && board[x][y] != '.'  ) {
    			char t = board[x][y];
    			if(root -> childrenNode[ t - 'a' ] != NULL) {
    				board[x][y] = '.';
    				curStr += t;
    				dfs(board, x, y, curStr, resSet, root -> childrenNode[ t - 'a' ]);
    				board[x][y] = t;
    				curStr = curStr.substr(0, curStr.size() - 1);
    			}
    		}
    	}
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    	vector<string> ans;
    	ans.clear();
    	
    	if(board.size() < 1) return ans;
    	
    	// construct trie
    	for(int i = 0; i < words.size(); i++) {
    		myTrie.addWord( words[i] );
    	}
    	TrieNode* root = myTrie.getRootNode();
    	unordered_set<string> resSet;
    	resSet.clear();
    	
    	// find result
    	for(int i = 0; i < board.size(); i++) {
    		for(int j = 0; j < board[0].size(); j++) {
    			char c = board[i][j];
    			if( root -> childrenNode[c - 'a'] != NULL ) {
    				string curStr = "";
    				curStr += c;
    				board[i][j] = '.';
    				dfs(board, i, j, curStr, resSet, root -> childrenNode[c - 'a']);
    				board[i][j] = c;
    			}
    		}
    	}
    	for(string s: resSet) {
    	    ans.push_back(s);
    	}
    	return ans;
    }
};
