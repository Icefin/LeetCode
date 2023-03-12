/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];

        priority_queue<pair<int, ListNode*>> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) pq.push({-lists[i]->val, lists[i]});
        }
        if (pq.empty()) return nullptr;

        ListNode* head = pq.top().second; pq.pop();
        if (head->next != nullptr) pq.push({-head->next->val, head->next});
        ListNode* temp = head;

        while (!pq.empty()) {
            temp->next = pq.top().second; pq.pop();
            temp = temp->next;
            if (temp->next != nullptr) pq.push({-temp->next->val, temp->next});
        }
        return head;
    }
};