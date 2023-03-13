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
class Solution{
public:
    bool is_same(TreeNode *leftRoot, TreeNode *rightRoot){
        if(leftRoot == nullptr && rightRoot == nullptr){
            return true;
        } 
        else if (leftRoot == nullptr || rightRoot == nullptr){
            return false;
        }
        
        if(leftRoot->val == rightRoot->val){
            return is_same(leftRoot->left , rightRoot->right) && is_same(leftRoot->right , rightRoot->left);
        } 
        
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return is_same(root->left, root->right);
    }
};