class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = findRoot(n, leftChild, rightChild);
        if (root == -1)
            return false;

        vector<bool> isVisited(n, false);
        int nodeCnt= dfs(root, leftChild, rightChild, isVisited);
        return (nodeCnt == n);
    }

private :
    int findRoot(int n, vector<int>& left, vector<int>& right) {
        unordered_set<int> children;
        children.insert(left.begin(), left.end());
        children.insert(right.begin(), right.end());
        
        for (int i = 0; i < n; i++) {
            if (children.find(i) == children.end()) {
                return i;
            }
        }
        
        return -1;
    }
    
    int dfs(int node, vector<int>& left, vector<int>& right, vector<bool>& isVisited) {
        if (node == -1)
            return 0;
        
        if (isVisited[node] == true)
            return -1;
        
        isVisited[node] = true;
        return (dfs(left[node], left, right, isVisited) + dfs(right[node], left, right, isVisited) + 1);
    }
};