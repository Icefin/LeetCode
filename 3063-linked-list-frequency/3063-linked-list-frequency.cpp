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
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int, int> frequencies;
        while (head != nullptr) {
            frequencies[head->val]++;   
            head = head->next;
        }
        
        ListNode* node = new ListNode();
        ListNode* res = node;
        for (auto& elem : frequencies) {
            node->next = new ListNode();
            node = node->next;
            node->val = elem.second;
        }
        ListNode* temp = res;
        res = res->next;
        delete temp;
        return res;
    }
};