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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && slow != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        stack<int> st;
        while (slow != nullptr) {
            st.push(slow->val);
            slow = slow->next;
        }
        int res = 0;
        ListNode* ptr = head;
        while (!st.empty()) {
            if (st.top() + ptr->val > res) {
                res = st.top() + ptr->val;
            }
            st.pop();
            ptr = ptr->next;
        }
        return res;
    }
};