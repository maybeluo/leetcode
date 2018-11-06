// I'm not aware of iterator in std::list when erase a node in list, thus haven't used it.
// A wonderful explanation and implementation here: http://songlee24.github.io/2015/05/10/design-LRU-Cache/
// L60 !!!

class doubleLinkedListNode {
public:
	int key, val;
	doubleLinkedListNode* prev, *next;
	doubleLinkedListNode(int _key, int _val) {
		key = _key;
		val = _val;
		prev = NULL;
		next = NULL;
	}
	doubleLinkedListNode() : key(0), val(0), prev(NULL), next(NULL) {}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        keyToPointer.clear();
        head = new doubleLinkedListNode(0, 0);
        tail = new doubleLinkedListNode(0, 0);
        head -> next = tail;
        tail -> prev = head;
    }
    
    ~LRUCache() {
    	delete head;
    	delete tail;
    }
    
    int get(int key) {
    	if(cap < 1) return -1;
    	
    	if( keyToPointer.find(key) != keyToPointer.end() ) {
    		doubleLinkedListNode *p = keyToPointer[key];
    		detachNode(p);
    		putToHead(p);
    		return p -> val;
    	}
        return -1;
    }
    
    void set(int key, int value) {
    	if(cap < 1) return ;
    	
        if( keyToPointer.find(key) != keyToPointer.end() ) {// contain the element
        	doubleLinkedListNode *p = keyToPointer[key];
        	p -> val = value;
        	detachNode(p);
        	putToHead(p);
        }
        else { // insert new element
        	if(size >= cap) { // delete tail element first
        		doubleLinkedListNode *p = tail -> prev;
        		int key = p -> key; // get the key
        		keyToPointer.erase(key);
        		detachNode(p);
        		delete p;
        		size --;
        	}
        	doubleLinkedListNode *q = new doubleLinkedListNode(key, value);
        	putToHead(q);
        	keyToPointer[key] = q;
        	size ++;
        }
    }
    
private:
	int cap = 0; // capacity
	int size = 0; // current number
	doubleLinkedListNode *head, *tail;
	unordered_map<int, doubleLinkedListNode*> keyToPointer; // key -> pointer to node in list
	
	void detachNode(doubleLinkedListNode *p) { // detach current node
		p -> prev -> next = p -> next;
		p -> next -> prev = p -> prev;
	}
	
	void putToHead(doubleLinkedListNode *p) { // put a node to after head
		head -> next -> prev = p;
		p -> next = head -> next;
		
		p -> prev = head;
		head -> next = p;
	}
	
};
