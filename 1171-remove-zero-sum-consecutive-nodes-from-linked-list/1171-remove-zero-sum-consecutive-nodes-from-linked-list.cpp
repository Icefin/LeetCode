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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* res = new ListNode(0, head);
        ListNode* curr = res;
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSumToNode;
        while (curr != nullptr) {
            prefixSum += curr->val;

            if (prefixSumToNode.find(prefixSum) != prefixSumToNode.end()) {
                ListNode* prev = prefixSumToNode[prefixSum];
                curr = prev->next;

                int temp = prefixSum + curr->val;
                while (temp != prefixSum) {
                    prefixSumToNode.erase(temp);
                    curr = curr->next;
                    temp += curr->val;
                }
                prev->next = curr->next;
            } 
            else{
                prefixSumToNode[prefixSum] = curr;
            }
            curr = curr->next;
        }
        return res->next;
    }
};