// quick sort. 
// Add begining and ending node.

pair<ListNode*, ListNode*> partitionList(ListNode* head, ListNode* end) {
	int n = 0, cnt = 0;
	ListNode *p = head -> next, *q = NULL, *r = NULL, *s = NULL;
	while(p != end) { // total elements
		n ++;
		p = p -> next;
	}
	ListNode *mid = head -> next;
	while(cnt < n / 2) {// find pivot
		mid = mid -> next;
		cnt ++;
	}
	int pivot = mid -> val;
	ListNode *m = new ListNode(pivot);

	s = head -> next;
	p = head, q = m, r = end;
	while(s != end) {
		if(s == mid) { // pivot node
			s = s -> next;
			delete(mid);
			continue;
		}
		ListNode* t = s -> next;
		if(s -> val < pivot) {// insert to the head
			p -> next = s;
			s -> next = NULL;
			p = s;
		}
		else if(s -> val == pivot) { // insert to mid
			q -> next = s;
			s -> next = NULL;
			q = s;
		}
		else { // insert to end
			s -> next = r;
			r = s;
		}
		s = t;
	}
	// merge head, mid, end
	p -> next = m;
	q -> next = r;
	return make_pair(m, q);	
}

void quickSortList(ListNode* head, ListNode* end) {
	if(head == NULL || head == end) return ; // no element
	if(head -> next == NULL || head -> next == end || head -> next -> next == end) return ;
	pair<ListNode*, ListNode*> p = partitionList(head, end);
	quickSortList(head, p.first);
	quickSortList(p.second, end);
}

ListNode* sortList(ListNode* head) {
	ListNode *hhead = new ListNode(0);
	hhead -> next = head;
	quickSortList(hhead, NULL);
	head = hhead -> next;
	hhead -> next = NULL;
	delete(hhead);
	return head;
}
