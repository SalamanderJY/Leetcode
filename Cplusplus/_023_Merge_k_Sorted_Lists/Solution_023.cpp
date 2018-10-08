/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct Comparator {
    bool operator() (const ListNode* n1, const ListNode* n2) {
        return (n1->val > n2->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comparator> pq;         
        for (auto node : lists) {
            if (node)
                pq.push(node);
        } 
        ListNode* result = new ListNode(0);
        ListNode* temp = result;  
        while (!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();
            temp->next = cur;
            if (cur->next != NULL)
                pq.push(cur->next);
            temp = temp->next;
        }         
        return result->next;
    }
};
