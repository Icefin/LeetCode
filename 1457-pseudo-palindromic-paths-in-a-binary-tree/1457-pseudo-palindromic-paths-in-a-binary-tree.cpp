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
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }
    
private :
    int dfs(TreeNode* node, int bitFlags) {
        bitFlags ^= (1 << node->val);
        if (node->left == nullptr && node->right == nullptr) {
            if (isPseudoPalindrome(bitFlags) == true)
                return 1;
            return 0;
        }
        
        int left = 0, right = 0;
        if (node->left != nullptr)
            left = dfs(node->left, bitFlags);
        if (node->right != nullptr)
            right = dfs(node->right, bitFlags);
        return left + right;
    }
    
    bool isPseudoPalindrome(int bitFlags) {
        int oddCnt = 0;
        for (int i = 1; i < 10; ++i) {
            if (bitFlags & (1 << i))
                oddCnt++;
        }
        return (oddCnt <= 1);
    }
};