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



// fast-slow pointer
class Solution {
public:
    TreeNode* creatBST(ListNode *head, ListNode* end) {
        if(head == NULL || end == NULL) return NULL;
        if(head == end) {
            TreeNode *p = (TreeNode*) malloc( sizeof(TreeNode) );
            p -> val = head -> val;
            p -> left = NULL;
            p -> right = NULL;
            return p;
        }
        bool flag = false;
        ListNode *pre = head, *slow = head, *fast = head;
        while(fast != end && fast -> next != end) {
            if(flag) pre = pre -> next;
            else flag = true;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        TreeNode* left = NULL, *right = NULL;
        if(pre != slow) {
            left = creatBST(head, pre);
        }
        right = creatBST(slow -> next, end);
        TreeNode* root = (TreeNode*) malloc(sizeof(TreeNode));
        root -> val = slow -> val;
        root -> left = left;
        root -> right = right;
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* end = head;
        while(end && end -> next) end = end -> next;
        TreeNode* root = creatBST(head, end);
        return root;
    }
};
