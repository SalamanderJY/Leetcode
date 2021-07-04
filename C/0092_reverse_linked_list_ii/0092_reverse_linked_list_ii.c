/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
   1 -> 2 -> 3 -> 4 -> 5

  prev curr
   1 -> 2 -> 3 -> 4 -> 5

           temp
  prev curr
   1 -> 2 -> 3 -> 4 -> 5

           temp
  prev curr
   1 -> 2    3 -> 4 -> 5
        | ------>

           temp
  prev curr
   1 -> 2 <- 3    4 -> 5
        | ------>

           curr
  prev temp
   1 -> 3 -> 2 -> 4 -> 5

           curr
  prev          temp
   1 -> 3 -> 2 -> 4 -> 5

*/

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) 
{
    if (head == NULL || m == n)
        return head;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* prev = dummy;
    dummy->next = head;
    for (int i = 0; i < m - 1; ++i)
        prev = prev->next;
    struct ListNode* curr = prev->next;
    for (int i = 0; i < n - m; ++i) {
        struct ListNode* temp = curr->next;
        curr->next = curr->next->next;
        temp->next = prev->next;
        prev->next = temp;
    }
    return dummy->next;
}