// Practice More!!! Test more cases, especially when list is 
//    a) NULL
//    b) Only one node
//    c) Two nodes
// TLE: L46 & L49. "if", NOT "while"
// WA: L34: "p != NULL && q != NULL", WITHNOT " -> next". Think carefully before choosing between "p->next != NULL" and "p != NULL"

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if( l1 == NULL ) return l2;
        if( l2 == NULL ) return l1;
        
        ListNode *head, *r;
        ListNode *p = l1, *q = l2;
        if(p -> val < q -> val) {
            head = l1;
            p = p ->next;
        }
        else {
            head = l2;
            q = q -> next;
        }
        r = head;
        
        while( p != NULL && q != NULL ){
            if(p -> val < q -> val) {
                r -> next = p;
                r = r -> next;
                p = p ->next;
            }
            else {
                r -> next = q;
                r = r -> next;
                q = q -> next;
            }
        }
        if( p != NULL ){
            r -> next = p;
        }
        if( q != NULL ){
            r -> next = q;
        }
        
        return head;
    }
};
