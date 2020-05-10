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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummyEnd = head;
        for (int i = 0; i < k; i++) {
            // list shorter than k
            if (!dummyEnd)
                return head;
            dummyEnd = dummyEnd->next;
        }
        auto newHead = reverse(head, dummyEnd);
        head->next = reverseKGroup(dummyEnd, k);
        return newHead;
    }
    
    ListNode* reverse(ListNode* start, ListNode* dummyEnd) {
        ListNode* prev = dummyEnd;
        while (start != dummyEnd) {
            auto temp = start->next;
            start->next = prev;
            prev = start;
            start = temp;
        }
        return prev;
    }
};
