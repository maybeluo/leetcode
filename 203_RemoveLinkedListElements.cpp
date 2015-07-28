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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p, *q;
        while(head != NULL && head -> val == val) {
            p = head -> next;
            head -> next = NULL;// use delete to remove a node? or just point to null?
            head = p;
        }
        
        p = head;
        while(p != NULL) {
            q = p -> next;
            while(q != NULL && q -> val == val) {
                q = q -> next;
            }
            p -> next = q;
            p = q;
        }
        return head;
    }
};
