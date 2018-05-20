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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;
        for (ListNode *it = head; it != NULL; it = it->next)
            length++;        
        if (k > length && length != 0)
            k %= length;       
        if (k == 0 || k == length || length == 0)
            return head;     
        ListNode *fast = head; 
        while (k > 1)
        {
            fast = fast->next;
            k--;
        }
        ListNode *slow = head, *prevslow = NULL;
        while (fast->next != NULL)
        {
            fast = fast->next;
            prevslow = slow;
            slow = slow->next;
        }
        prevslow->next = NULL;
        fast->next = head;
        head = slow;
        return head;
    }
};