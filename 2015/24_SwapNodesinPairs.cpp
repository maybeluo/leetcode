// One must be careful enough to handle list.
// Keypoint of solve this type of problem is multipule pointers. It's common that uses one pointer to record the priveous position of the node to be processed.
// In the solution below, three pointers are used:
//  1) p & q are the node's pointers to be swaped. q = p -> next
//  2) r is the previous pointers of p, i.e. r -> next = p
// Note after the swapping operation, the order of p and q are inverted, thus need to invert again after the swapping.
// TLE 1 times: wrong order of L27 & L28 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* p = head;
        ListNode* q = head;
        if( q != NULL && q-> next != NULL) q = q -> next;
        else return head; // only a node
        
        head = head -> next;
        p -> next = q -> next;
        head -> next = p;
        
        swap(p, q);
        if(q -> next == NULL) return head;
        
        ListNode* r = head;
        p = p -> next;
        q = q -> next;
        int cnt = 0;
        while( q -> next != NULL ){
            r = r -> next;
            p = p -> next;
            q = q -> next;
            cnt ++;
            if(cnt%2){
                r -> next = p -> next;
                p -> next = q -> next;
                q -> next = p;
                swap(p, q);
            }
        }
        return head;
    }
};
