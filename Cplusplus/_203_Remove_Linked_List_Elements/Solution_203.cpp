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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* curr = head; 
        ListNode* prev = fakeHead;
        while (curr != NULL) {
            if (curr->val == val) {
                prev->next = curr->next;
            } 
            else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        return fakeHead->next;
    }
};