// WA for neglecting L34.

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
        if(head == NULL) return head;
        ListNode* p = head, *q, *r;
        int flag = 1;
        head = NULL;
        while(p != NULL) {
            q = p->next;
            while(q!=NULL && p->val == q->val){
                q = q->next;
            }
            if(flag && p->next == q) {
                flag = 0; // head founded.
                head = p;
                r = p;
            }
            else if(p->next == q) {
                r -> next = p;
                r = p;
            }
            p = q;
        }
        r -> next = NULL;
        return head;
    }
};
