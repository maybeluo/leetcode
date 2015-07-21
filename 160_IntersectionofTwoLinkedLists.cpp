// Time complexity: O(n + m)
// Space: O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0, b = 0;
        ListNode *p = headA, *q = headB;
        if(headA == NULL || headB == NULL) return NULL;
        
        // get the lenght of A and B
        while(p->next != NULL) {
            p = p -> next;
            a ++;
        }
        while(q->next != NULL) {
            q = q -> next;
            b ++;
        }
        // if intersect, p must be same with q
        if(p != q) return NULL;
        
        // let A be the longer list
        if(a < b) {
            swap(headA, headB);
            swap(a, b);
        }
        p = headA, q = headB;
        for(int i = 0; i < a - b; i++) {
            p = p -> next;
        }
        
        while(p != q) {
            p = p -> next;
            q = q -> next;
        }
        return p;
        
    }
};
