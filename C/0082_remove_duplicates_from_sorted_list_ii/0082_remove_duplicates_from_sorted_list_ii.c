/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* current = head;
    struct ListNode* prev = dummy;

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