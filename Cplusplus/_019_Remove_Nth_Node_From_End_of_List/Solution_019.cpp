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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n <= 0)
          return NULL;   
        ListNode* tempHead = new ListNode(0);
        tempHead->next = head;
        ListNode* first = tempHead;
        ListNode* second = tempHead;
        int i = 0;
        while (i < n) {
            second = second->next;
            i++;
        } 
        while (second->next != NULL) {
            first = first->next;
            second = second->next;
        }  
        first->next = first->next->next;  
        return tempHead->next;       
    }
};
