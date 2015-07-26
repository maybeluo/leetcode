const int maxAlphabet = 27;

class TrieNode {
public:
    int count;
    TrieNode *childrenNode[maxAlphabet];
    // Initialize your data structure here.
    TrieNode() {
        count = 0;
        for(int i = 0; i < maxAlphabet; i++) {
            childrenNode[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            if( node -> childrenNode[ word[i] - 'a' ] == NULL ) {
                TrieNode *tmp = new TrieNode();
                node -> childrenNode[ word[i] - 'a' ] = tmp;
            }
            node = node -> childrenNode[ word[i] - 'a' ];
        }
        node -> count += 1;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = root;
        int i = 0;
        while(i < word.size() && node != NULL) {
            node = node -> childrenNode[ word[i] - 'a' ];
            i ++;
        }
        // RE: if(i == word.size() && node -> count > 0) return true;
        // node can be NULL 
        if(node == NULL || node -> count < 1) return false;
        else return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root; 
        int i = 0;
        while(i < prefix.size() && node != NULL) {
            node = node -> childrenNode[ prefix[i] - 'a' ];
            i ++;
        }
        if( node != NULL ) return true; // NOT if( i == prefix.size() ) return true;
        else return false;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
