// Divide and conquer. O(m1*logm1 + m2*logm2 + m3*logm3...)
// TLE many times: L39, L42. "if", not "while"

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
    ListNode* merge2Lists(ListNode* p, ListNode* q) {
        if(p == NULL) return q;
        if(q == NULL) return p;
        ListNode* head;
        if(p->val < q->val) {
            head = p;
            p = p->next;
        }
        else {
            head = q;
            q = q->next;
        }
        ListNode* r = head;
        while(p!=NULL && q!=NULL) {
            if(p->val < q->val){
                r->next = p;
                r = r->next;
                p = p->next;
            }
            else{
                r->next = q;
                r = r->next;
                q = q->next;
            }
        }
        if(p != NULL) {
            r -> next = p;
        }
        if(q != NULL) {
            r -> next = q;
        }
        return head;
    }
    
    ListNode* dc(vector<ListNode*>& lists, int l, int r) {
        if(l > r) return NULL;
        if(l == r) return lists[l];
        int mid = (l + r)/2;
        ListNode* head1 = dc(lists, l, mid);
        ListNode* head2 = dc(lists, mid+1, r);
        return merge2Lists(head1, head2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* head = NULL;
        if(n < 1) return head;
        return dc(lists, 0, n-1);
    }
};
