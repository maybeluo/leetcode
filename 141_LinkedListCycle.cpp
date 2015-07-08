// Fast and slow pointers.
// In every action, the distance between fast and slow pointers increase 1. 
// Thus it's sufficient to determine whether there is a circle. No matter the element in circle is even or odd.

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
    bool hasCycle(ListNode *head) {
        ListNode* p = head, *q;
        if(head == NULL) return false;
        if(head->next == NULL ) return false;
        q = head -> next -> next;
        while(p != NULL && q != NULL) {
            if(p == q) return true;
            if(q -> next != NULL) q = q->next;
            else return false;
            p = p -> next;
            q = q -> next;
        }
        return false;
    }
};
