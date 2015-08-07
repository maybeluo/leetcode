void connect(TreeLinkNode* root) {
	int flag = 0;
	TreeLinkNode *p = NULL, *q = NULL, *t = NULL;
	p = root;
	while(p != NULL) {
		q = p;
		flag = 0;
		while(q != NULL) {
			if(!flag) {
				flag = 1;
				while(q && (q->left == NULL && q->right == NULL ) ) q = q -> next;
				t = q;
				if(q == NULL) break;
			}
			if(q -> left && q->right) q -> left -> next = q -> right;

			TreeLinkNode *r = q -> next;
				while(r && (r->left == NULL && r->right == NULL) ) r = r -> next;
				if(r) {
					if(q -> right) q -> right -> next = r -> left ? r -> left : r -> right;
					else q -> left -> next = r -> left ? r -> left : r -> right;
			}
			q = r;
		}
		if(t == NULL) break;
		p = t -> left ? t->left : t -> right;
	}
	return ;
}
