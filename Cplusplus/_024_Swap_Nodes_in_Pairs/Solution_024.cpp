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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        while (pre->next != NULL && pre->next->next != NULL) {
            ListNode* temp = pre->next->next;
            pre->next->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
            pre = temp->next;
        }
        return dummy->next;
    }
};