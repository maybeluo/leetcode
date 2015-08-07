void connect(TreeLinkNode* root) {
	TreeLinkNode *p = root;
	while( p != NULL) {
		TreeLinkNode *q = p;
		while(q != NULL && q -> left != NULL) {
			q -> left -> next = q -> right;
			if(q -> next) q -> right -> next = q -> next -> left;
			q = q -> next;
		}	
		p = p -> left;
	}
	return ;
}
