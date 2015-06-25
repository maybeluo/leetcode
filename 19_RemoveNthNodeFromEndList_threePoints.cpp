// WA 2 times:
//  1) L41: need to see if q->next is NULL or not
//  2) L27, L36, L41: use 'a->next', NOT 'a'

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( head == NULL || head->next == NULL) return NULL;
        
        ListNode *p = head, *q = head, *r = head;
        int i = 1;
        while( i < n && p != NULL ) {
            p = p->next;
            i ++;
        }
        
        assert( i >= n );//make sure that the list contains at least n elements.
        
        if(p->next != NULL) {
            p = p->next;
            q = q->next;
        }
        else{// exactly n elements, remove the head element.
            head = head->next;
            return head;
        }
        
        while(p->next != NULL){
           p = p->next;
           q = q->next;
           r = r->next;
        }
        if(q->next == NULL ) r->next = NULL;
        else r->next = q->next;
        return head;
    }
};
