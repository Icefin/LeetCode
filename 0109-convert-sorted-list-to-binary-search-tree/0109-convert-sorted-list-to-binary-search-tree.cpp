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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v_nodes;
        ListNode* temp = head;
        while (temp) {
            v_nodes.push_back(temp->val);
            temp = temp->next;
        }
        if (v_nodes.size() == 0)
            return nullptr;
        TreeNode* ans = new TreeNode();
        vectorToBST(ans, v_nodes, 0, v_nodes.size() - 1);
        return (ans);
    }
    
    void vectorToBST(TreeNode* root, vector<int>& v_nodes, int left, int right) {
        int mid = (left + right + 1) / 2;
        root->val = v_nodes[mid];
        
        if (left <= mid - 1) {
            root->left = new TreeNode();
            vectorToBST(root->left, v_nodes, left, mid - 1);
        }
        if (mid + 1 <= right) {
            root->right = new TreeNode();
            vectorToBST(root->right, v_nodes, mid + 1, right);    
        }
    }
};