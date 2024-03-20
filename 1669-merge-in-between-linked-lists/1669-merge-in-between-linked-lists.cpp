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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* begin = list1;
        for (int i = 0; i < a - 1; ++i)
            begin = begin->next;
        
        ListNode* end = begin;
        for (int i = 0; i < b - a + 2; ++i)
            end = end->next;
        
        begin->next = list2;
        ListNode* ptr = list2;
        while (ptr ->next != nullptr)
            ptr = ptr->next;
        ptr->next = end;
        return list1;
    }
};