// TLE: L43
// RTE: L33, L34, L38, L42

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* headGt = NULL, *headLs = NULL, *p = NULL, *q = NULL, *r = head;
        int pFlag = 0, qFlag = 0;
        while( r != NULL ) {
            if(r->val < x) {// less than
                if( !qFlag ) {
                    qFlag = 1;
                    headLs = r;
                }
                else{
                    q -> next = r;
                }
                q = r;
            }
            else{ // large
                if( !pFlag ) {
                    pFlag = 1;
                    headGt = r;
                }
                else {
                    p -> next = r;
                }
                p = r;
            }
            r = r -> next;
        }
        
        if(p == NULL && q == NULL) return head;
        else if(p == NULL && q != NULL){// all are less than
            q -> next = NULL;
            return headLs;
        }
        else if(p != NULL && q == NULL){// all are larger than
            p -> next = NULL;
            return headGt;
        }
        else {
            p -> next = NULL;
            q -> next = headGt;
            return headLs;
        }
        
    }
};
