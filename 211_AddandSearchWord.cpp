//WA many times in L45. use "||", not return immediately.

const int maxAlphabet = 27;

class TrieNode {
public:
    int count;
    TrieNode* childrenNode[maxAlphabet];
    
    TrieNode() {
        count = 0;
        for(int i = 0; i < maxAlphabet; i++) {
            childrenNode[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.size(); i++) {
            if( p -> childrenNode[ word[i] - 'a' ] == NULL ) {
                p -> childrenNode[ word[i] - 'a' ] = new TrieNode();
            }
            p = p -> childrenNode[ word[i] - 'a' ];
        }
        p -> count += 1;
    }
    
    bool dfsSearch(TrieNode *p, string word, int dep) {
        if(dep > word.size()) return false;
        if(dep == word.size()) {
            if(p -> count > 0) return true;
            else return false;
        }
        if(word[dep] == '.') {
            bool flag = false;
            for(int i = 0; i < maxAlphabet; i++) {
                if(p -> childrenNode[i] != NULL) {
                    flag = flag || dfsSearch(p -> childrenNode[i], word, dep + 1);
                }
            }
            return flag;
        }
        else {
            if( p -> childrenNode[ word[dep] - 'a' ] != NULL ) {
                return dfsSearch(p -> childrenNode[ word[dep] - 'a' ], word, dep + 1);
            }
        }
        return false;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        TrieNode *p = root;
        return dfsSearch(p, word, 0);
    }
    
private:
    TrieNode *root;
    
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
