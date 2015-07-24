// Version 1: use two Hash Map to store the address. Time complexity: O(n), Space Complexity: O(n)
// Version 2: A more smart way, see http://www.cnblogs.com/zuoyuan/p/3745126.html . Space Complexity: O(1)

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
 
// ver 1.
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p, *q, *targetHead;
        unordered_map<RandomListNode*, int> sourceTable;
        unordered_map<int, RandomListNode*> targetTable;
        sourceTable.clear();
        targetTable.clear();
        
        if(head == NULL) return NULL;
        
        int idx = 0;
        targetHead = (RandomListNode*) malloc( sizeof(RandomListNode) );
        targetHead -> label = head ->label;
        
        //sourceTable.insert( make_pair<RandomListNode*, int>(head, idx) );
        sourceTable[head] = idx;
        //targetTable.insert( make_pair<int, RandomListNode*>(idx, targetHead) );
        targetTable[idx] = targetHead;
        
        p = head -> next;
        q = targetHead;
        while(p != NULL) {
            idx += 1;
            RandomListNode *r = (RandomListNode*) malloc( sizeof(RandomListNode) );
            r -> label = p -> label;
            q -> next = r;
            q = r;
            //sourceTable.insert( make_pair<RandomListNode*, int>(p, idx) );
            sourceTable[p] = idx;
            //targetTable.insert( make_pair<int, RandomListNode*>(idx, q) );
            targetTable[idx] = q;
            p = p -> next;
        }
        q -> next = NULL;
        
        p = head, q = targetHead;
        while(p != NULL && q != NULL) {
            RandomListNode *r = p -> random;
            if(r == NULL) {
                q -> random = NULL;
            }
            else {
                idx = sourceTable[r];
                q -> random = targetTable[idx];
            }
            p = p -> next;
            q = q -> next;
        }
        
        return targetHead;
    }
};

// ver 2. 
// RE many times for lacking L115.
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        
        RandomListNode *p, *q, *targetHead;
        
        // double the list
        p = head;
        while(p != NULL) {
            q = p -> next;
            RandomListNode *r = (RandomListNode*) malloc( sizeof(RandomListNode) );
            r -> label = p -> label;
            p -> next = r;
            r -> next = q;
            p = q;
        }
        
        // find the random pointers.
        p = head;
        while(p != NULL) {
            q = p -> next;
            if(p -> random != NULL) {
                q -> random = p -> random -> next;
            }
            else {
                q -> random = NULL;
            }
            p = q -> next;
        }

        // split the list
        p = head;
        targetHead = head -> next;
        while(p != NULL) {
            q = p -> next;
            if(q -> next != NULL) {
                p -> next = q -> next;
                p = q -> next;
                q -> next = p -> next;
            }
            else {
                p -> next = NULL;
                q -> next = NULL;
                p = NULL;
            }
        }
        
        return targetHead;
    }
};
