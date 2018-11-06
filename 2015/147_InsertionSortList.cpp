class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return head;
        
        ListNode *newHead = head;
        head = head -> next;
        newHead -> next = NULL;
        ListNode *p = head, *q = newHead, *r, *t;
        while(p != NULL) {
            q = newHead;
            r = p -> next;
            if(p -> val >= q ->val) {
                p -> next = q;
                newHead = p;
            }
            else {
                // t is previous node of q
                while( q != NULL && p -> val < q ->val) {
                    t = q;
                    q = q -> next;
                }
                t -> next = p;
                p -> next = q;
            }
            p = r;
        }
        
        // reverse list
        p = newHead, q = newHead -> next;
        while(q != NULL) {
            r = q -> next;
            q -> next = p;
            p = q;
            q = r;
        }
        newHead -> next = NULL;
        newHead = p;
        
        return newHead;
    }
};
