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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        ListNode* temp = head;
        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        int tmp = arr[k - 1];
        arr[k - 1] = arr[n - k];
        arr[n - k] = tmp;
        ListNode* res = new ListNode(arr[0]);
        temp = res;
        for (int i = 1; i < n; i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return res;
    }
};