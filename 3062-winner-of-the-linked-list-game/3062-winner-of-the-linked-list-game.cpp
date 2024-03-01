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
    string gameResult(ListNode* head) {
        uint8_t oddPoint = 0;
        uint8_t evenPoint = 0;
        
        while (head != nullptr) {
            if (head->val < head->next->val)
                oddPoint++;
            else
                evenPoint++;
            head = head->next->next;
        }
        
        if (oddPoint > evenPoint)
            return "Odd";
        if (oddPoint < evenPoint)
            return "Even";
        return "Tie";
    }
};