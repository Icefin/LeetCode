class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        for (int i = 0; i < heights.size() - 1; ++i) {
            if (heights[i] >= heights[i + 1])
                continue;
            
            int diff = heights[i + 1] - heights[i];
            bricks -= diff;
            pq.push(diff);
            while (bricks < 0 && pq.empty() == false && ladders > 0) {
                bricks += pq.top();
                pq.pop();
                ladders--;
            }
            if (bricks < 0)
                return i;
        }
        return heights.size() - 1;
    }
};