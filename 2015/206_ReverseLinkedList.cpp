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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head, *q, *r; 
        if(head == NULL) return head;
        q = p -> next;
        while(q != NULL) {
            r = q -> next;
            q -> next = p;
            p = q;
            q = r;
        }
        head -> next = NULL;
        head = p;
        return head;
    }
};
