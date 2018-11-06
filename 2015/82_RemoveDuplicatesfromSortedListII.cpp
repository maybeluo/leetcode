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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current = head, *runner = head, *newHead = NULL, *follow = NULL;
        while(current != NULL) {
            runner = current -> next;
            while(runner != NULL && runner -> val == current -> val) runner = runner -> next;
            if(runner == current -> next) {
                if(newHead == NULL) {
                    newHead = current;
                }
                else {
                    follow -> next = current;
                }
                follow = current;
                follow -> next = NULL;
            }
            current = runner;
        }
        return newHead;
    }
};
