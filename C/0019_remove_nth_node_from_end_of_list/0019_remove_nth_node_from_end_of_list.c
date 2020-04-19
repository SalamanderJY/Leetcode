/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
        if (head == NULL || n <= 0)
            return NULL;   
        struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
        dummyHead->next = head;
        struct ListNode* first = dummyHead;
        struct ListNode* second = dummyHead;
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
        return dummyHead->next;    
}