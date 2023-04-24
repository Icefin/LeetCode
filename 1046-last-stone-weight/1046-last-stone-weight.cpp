class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq { less<int>(), stones };
        int y = 0, x = 0;
        while(pq.size() > 1){
            y = pq.top(); pq.pop();
            x = pq.top(); pq.pop();
            
            if (y - x != 0){
                pq.push(y - x);
            }
        }
        
        if (pq.size() == 1){
            return pq.top();
        }
        else{
            return 0;
        }
    }
};