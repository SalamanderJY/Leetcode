/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *pre = &dummy;
    while (pre->next && pre->next->next) {
        struct ListNode* temp1 = pre->next;
        struct ListNode* temp2 = pre->next->next;
        pre->next = temp2;
        temp1->next = temp2->next;
        temp2->next = temp1;
        pre = pre->next->next;
    }
    return dummy.next;
}