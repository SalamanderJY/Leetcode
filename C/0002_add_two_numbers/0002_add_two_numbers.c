/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *list1 = l1;
    struct ListNode *list2 = l2;
    struct ListNode *curr = dummy;
    int carry = 0;
    
    while (list1 || list2) {
        int x = list1 ? list1->val : 0;
        int y = list2 ? list2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode)); 
        newNode->val = sum % 10;
        newNode->next = NULL;
        curr->next = newNode;
        curr = curr->next;
        
        if (list1)
            list1 = list1->next;
        if (list2)
            list2 = list2->next;
    }
    
    if (carry > 0) {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode)); 
        newNode->val = carry;
        newNode->next = NULL;
        curr->next = newNode;
    }
 
    return dummy->next;
}