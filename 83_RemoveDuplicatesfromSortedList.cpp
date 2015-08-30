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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head, *q = head;
        if(p == NULL) return p;

        while(p != NULL) {
            q = p->next;
            while( q!= NULL && p->val == q->val) {
                ListNode *t = q;
                q = q->next;
                delete t;
            }
            p -> next = q;
            p = q;
        }
        
        return head;
    }
};
