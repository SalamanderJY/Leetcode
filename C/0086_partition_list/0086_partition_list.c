/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode* small = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* ts = small;  
    struct ListNode* large = (struct ListNode *)malloc(sizeof(struct ListNode));;
    struct ListNode* tl = large;
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