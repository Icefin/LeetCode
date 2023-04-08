/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* map[101];
    void dfs(Node* node){   
        map[node->val] = new Node(node->val);
        for(auto neigh : node->neighbors)
        {
            if(map[neigh->val] == nullptr)
                dfs(neigh);    
            map[node->val]->neighbors.emplace_back(map[neigh->val]);
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        for(int i = 0 ; i <= 100; i++)
            map[i] = nullptr;
        dfs(node);
        return map[1];
    }
};