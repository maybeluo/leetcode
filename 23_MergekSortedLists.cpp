// Divide and conquer. O(nk), assume each list has n elements exactly.
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


// not recurision, but change step: 2, 4, 8, 16, ...
ListNode* merge2SortedLists(ListNode* head1, ListNode* head2) {
	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;
	ListNode *p = head1, *q = head2, *r = NULL, *newHead = NULL;
	if(head1 -> val < head2-> val) {
		newHead = head1;
		p = head1 -> next;
	}
	else{
		newHead = head2;
		q = head2 -> next;
	} 
	r = newHead;
	while(p && q) {
		if(p -> val < q -> val) {
			r -> next = p;
			r = p;
			p = p -> next;
		}
		else{
			r -> next = q;
			r = q;
			q = q -> next;
		}
	}
	r -> next = p ? p : q;
	return newHead;
}

ListNode* mergeKLists(vector<ListNode*> & lists) {
	int n = lists.size(), h = 1;
	if(n < 1) return NULL;
	vector<int> vp;
	while(h < n) {
		h <<= 1;
		vp.push_back(h);
	}
	for(int k = 0; k < vp.size(); k++) {
		int step = vp[k];// 2^(k+1)
		for(int i = 0; i < n; i+= step) {
			if( i + step/2 < n ) lists[i] = merge2SortedLists(lists[i], lists[i + step/2]);
		}
	}
	return lists[0];
}
