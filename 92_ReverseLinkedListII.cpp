// L30.

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int cnt = 1;
        ListNode* p = head, *q = head, *r, *s, *t;
        s = NULL;
        while(p != NULL && cnt < m) {
            s = p;
            p = p -> next;
            cnt ++;
        }
        t = p;
        if(p == NULL) return head; // element less than m
        
        q = p -> next;
        if(q == NULL) return head;
        
        while(cnt <= n) {
            if(cnt == n || q == NULL) {
                if(s == NULL) 
                    head = p;
                else 
                    s -> next = p;
                t -> next = q;
                return head;
            }
            r = q -> next;
            q -> next = p;
            p = q;
            q = r;
            cnt ++;
        }
        return head;
    }
};
