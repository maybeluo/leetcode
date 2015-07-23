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
        if(head == NULL || head -> next == NULL) return head;
        ListNode *p = head, *q = head->next, *r = NULL;
        while(q != NULL) {
            r = q -> next;
            q -> next = p;
            p = q;
            q = r;
        }
        head -> next = NULL;
        head = p;
        return p;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *p = head, *q = head;
        int n = 0, cnt = 0;
        while(p != NULL) {
            n ++;
            p = p -> next;
        }
        p = head;
        
        while(cnt < n/2) {
            p = p -> next;
            cnt ++;
        }
        
        q = reverseList(p);
        p = head;
        while(p != NULL && q != NULL) {
            if(p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};
