/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        auto node = um_node.find(root);
        if (node != um_node.end()) {
            return node->second;
        }
        
        auto* ans = new NodeCopy(root->val);
        um_node[root] = ans;
        ans->left = copyRandomBinaryTree(root->left);
        ans->right = copyRandomBinaryTree(root->right);
        ans->random = copyRandomBinaryTree(root->random);
        return ans;
    }
    
private :
    unordered_map<Node*, NodeCopy*> um_node;
};