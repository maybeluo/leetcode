// Two pointer. 'q' the the last (n+1)-th node.

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
        
        ListNode *p = head, *q = head;
        int i = 1;
        while( i < n && p != NULL ) {
            p = p->next;
            i ++;
        }
        
        assert( i >= n );//make sure that the list contains at least n elements.
        
        if(p->next != NULL) {
            p = p->next;
        }
        else{// exactly n elements, remove the head element.
            head = head->next;
            return head;
        }
        
        while(p->next != NULL){
           p = p->next;
           q = q->next;
        }
        
        q->next = q->next->next;
        return head;
    }
};
