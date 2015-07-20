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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* p = head, *q, *rHead;
        while(p != NULL) {
            n ++;
            p = p -> next;
        }
        if(n < 1) return head;// NULL
        
        k %= n;
        if(k < 1) return head; // do not remote
        
        int i = 0;
        p = head;
        while(i < n - k - 1) {
            p = p -> next;
            i ++;
        }
        
        rHead = p -> next;
        p -> next = NULL;
        p = rHead;
        while(p -> next != NULL) {
            p = p -> next;
        }
        p -> next = head;
        head = rHead;
        
        return head;
    }
};
