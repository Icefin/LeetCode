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
    int amountOfTime(TreeNode* root, int start) {
        buildGraph(root);
        return findMaxDist(start);
    }
    
private :
    void buildGraph(TreeNode* node) {
        if (node == nullptr)
            return;
        
        if (node->left != nullptr) {
            graph[node->val].push_back(node->left->val);
            graph[node->left->val].push_back(node->val);
            buildGraph(node->left);
        }
        if (node->right != nullptr) {
            graph[node->val].push_back(node->right->val);
            graph[node->right->val].push_back(node->val);
            buildGraph(node->right);
        }
    }
    
    int findMaxDist(int start) {
        int res = 0;
        queue<pair<int, int>> q;
        q.push({start, 0});
        
        while (q.empty() == false) {
            int curr = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            for (int i = 0; i < graph[curr].size(); ++i) {
                if (graph[curr][i] == 0)
                    continue;
                int next = graph[curr][i];
                graph[curr][i] = 0;
                q.push({next, dist + 1});
                if (dist > res)
                    res = dist;
            }
        }
        return res;
    }
    
private :
    unordered_map<int, vector<int>> graph;
};