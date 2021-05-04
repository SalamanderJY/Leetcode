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
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = head;
        ListNode* prev = dummy;
        
        while (current != NULL && current->next != NULL) {
            int count = 1;
            while (current->next != NULL && current->val == current->next->val) {
                current = current->next;
                count++;
            }
            if (count == 1) {
                prev = current;
                current = current->next;
            } else {
                current = current->next;
                prev->next = current;
            }
        }
        return dummy->next;
    }
};