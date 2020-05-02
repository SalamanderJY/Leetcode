struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if (l1 == NULL || l2 == NULL) {
        return l1 ? l1 : l2;
    }
    struct ListNode head;
    head.next = NULL;
    struct ListNode *tail = &head;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return head.next;
}

struct ListNode* merge(struct ListNode** lists, int l, int r)
{
    if (l == r) {
        return lists[l];
    }
    if (l > r) {
        return NULL;
    }
    int mid = l + (r - l) / 2;
    struct ListNode *p1 = merge(lists, l, mid);
    struct ListNode *p2 = merge(lists, mid + 1, r);
    return mergeTwoLists(p1, p2);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) 
{
    if (listsSize == 0) {
        return NULL;
    }
    return merge(lists, 0, listsSize - 1);
}