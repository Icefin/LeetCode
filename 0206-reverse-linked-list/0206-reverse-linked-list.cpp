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
private :
    ListNode* ret;
    ListNode* ReverseListRecur(ListNode* head) {
        if (head->next == nullptr) {
            ret = head;
            return head;
        }

        ListNode* temp = ReverseListRecur(head->next);
        temp->next = head;
        return head;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* p_ret = ReverseListRecur(head);
        p_ret->next = nullptr;
        return ret;
    }
};