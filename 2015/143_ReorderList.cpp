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

    // inverse head
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
    
    ListNode* merge2List(ListNode* head1, ListNode* head2) {
        ListNode* p = head1, *q = head2;
        if(p == NULL) return q;
        if(q == NULL) return p;
        
        int flag = 1;
        ListNode* head = p;
        ListNode* r = p;
        p = p -> next;
        while(p != NULL && q != NULL) {
            if(flag) {
                r -> next = q;
                r = r -> next;
                q = q -> next;
                flag = 0;
            }
            else{
                r -> next = p;
                r = r -> next;
                p = p -> next;
                flag = 1;
            }
        }
        if(p != NULL) r -> next = p;
        if(q != NULL) r -> next = q;
        return head;
    }
    
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        ListNode* head1 = head, *head2 = head->next;
        if(head2 == NULL) return;
        
        // total elements
        int n = 0;
        ListNode* p = head1, *q = head2, *r = head2;
        p = head;
        while(p != NULL) {
            n ++;
            p = p->next;
        }
        
        // position to seperate the list
        int cnt = 0;
        p = head;
        while(p != NULL && cnt < (n-1)/2) {
            p = p->next;
            cnt ++;
        }
        head2 = p -> next;
        p ->next = NULL;
        
        // inverse head2
        head2 = reverseList(head2);
        head = merge2List(head1, head2);
        
        return ;
    }
};
