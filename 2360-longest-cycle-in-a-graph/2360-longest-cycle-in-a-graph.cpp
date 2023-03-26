class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> isVisited(n, 0);
        
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (isVisited[i] != 0)
                continue ;
            
            int pos = getCycleBeginPosition(edges, isVisited, i);
            if (pos != -1) {
                int cycle_cnt = 0;
                while (isVisited[pos] != 2) {
                    isVisited[pos] = 2;
                    pos = edges[pos];
                    cycle_cnt++;
                }
                ans = max(cycle_cnt, ans);
            }
        }
        return (ans);
    }
    
private :
    int getCycleBeginPosition(vector<int>& edges, vector<int>& isVisited, int start) {
        isVisited[start] = 1;
        int slow = start;
        if (slow == -1)
            return -1;
        int fast = edges[slow];
        while (slow != -1 && fast != -1 && isVisited[slow] != 2 && isVisited[fast] != 2) {
            isVisited[slow] = 1;
            isVisited[fast] = 1;
            if (slow == fast)
                break;
            slow = edges[slow];
            if (edges[fast] == -1)
                return -1;
            fast = edges[edges[fast]];
        }
        if (slow == fast)
            return slow;
        return -1;
    }
};