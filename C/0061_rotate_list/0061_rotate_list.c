struct ListNode* rotateRight(struct ListNode* head, int k)
{
    int length = 0;
    struct ListNode* it;
    for (it = head; it != NULL; it = it->next)
        length++;        
    if (k > length && length != 0)
        k %= length;       
    if (k == 0 || k == length || length == 0)
        return head;     
    struct ListNode *fast = head; 
    while (k > 1) {
        fast = fast->next;
        k--;
    }
    struct ListNode *slow = head, *prevSlow = NULL;
    while (fast->next != NULL) {
        fast = fast->next;
        prevSlow = slow;
        slow = slow->next;
    }
    prevSlow->next = NULL;
    fast->next = head;
    head = slow;
    return head;
}