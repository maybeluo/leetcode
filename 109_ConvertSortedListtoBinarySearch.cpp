class Solution {
public:
    TreeNode* dfs(ListNode *head, int n) {
        if(head == NULL || n < 1) return NULL;
        if(n == 1) {
            TreeNode *root = new TreeNode(head -> val);
            return root;
        }
        
        int i = 0;
        ListNode *p = head, *q = head;
        while( i < n/2) {
            i ++;
            q = p;
            p = p -> next;
        }
        TreeNode *root = new TreeNode(p -> val);
        // split list into two
        q -> next = NULL;
        q = p -> next;
        p -> next = NULL;
        
        root -> left = dfs(head, i);
        root -> right = dfs(q, n - i - 1);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode *p = head;
        while(p != NULL) {
            p = p->next;
            n ++;
        }
        return dfs(head, n);
    }
};
