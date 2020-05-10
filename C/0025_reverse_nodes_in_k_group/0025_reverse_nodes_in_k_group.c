/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* start, struct ListNode* dummyEnd)
{
    struct ListNode *prev = dummyEnd;
    while (start != dummyEnd) {
        struct ListNode *temp = start->next;
        start->next = prev;
        prev = start;
        start = temp;
    }
    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    struct ListNode *dummyEnd = head;
    for (int i = 0; i < k; i++) {
        if (!dummyEnd) {
            return head;
        }
        dummyEnd = dummyEnd->next;
    }
    struct ListNode* newHead = reverse(head, dummyEnd);
    head->next = reverseKGroup(dummyEnd, k);
    return newHead;
}
