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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        
        ListNode* p = head, *q = head->next;
        while(p != q) {
            if(p == NULL || q == NULL)
                return NULL;
            if(q -> next != NULL)
                q = q->next->next;
            else
                return NULL;
            p = p -> next;
        }
        
        //find pointer in circle
        p = p -> next;
        q = head;
        while(p != q){
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
