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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* small = new ListNode(0);
        ListNode* ts = small;  
        ListNode* large = new ListNode(0);
        ListNode* tl = large;
        while (head != 0) {
            if (head->val < x) {
                ts->next = head;
                ts = ts->next;
            } else {
                tl->next = head;
                tl = tl->next;
            }
            head = head->next;
        }
        tl->next = NULL; 
        ts->next = large->next; 
        return small->next;
    }
};