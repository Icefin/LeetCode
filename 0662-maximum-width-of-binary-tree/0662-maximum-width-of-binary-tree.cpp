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
typedef unsigned long long ull;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ull ans = 0;
        deque<pair<TreeNode*, pair<ull, int>>> dq; //node, idx, level
        dq.push_back({root, {1, 0}});
        int plev = 0;
        while(!dq.empty()) {
            pair<TreeNode*, pair<long long, int>> curr = dq.front();
            TreeNode* cNode = curr.first;
            ull cidx = curr.second.first;
            int clev = curr.second.second;
            if (clev != plev) {
                plev = clev;
                ull bidx = dq.back().second.first;
                if (bidx - cidx > ans)
                    ans = bidx - cidx;
            }
            dq.pop_front();
            if (cNode->left != nullptr) {
                dq.push_back({cNode->left, {2 * cidx - 1, clev + 1}});
            }
            if (cNode->right != nullptr) {
                dq.push_back({cNode->right, {2 * cidx, clev + 1}});
            }
        }
        return (ans + 1);
    }
};