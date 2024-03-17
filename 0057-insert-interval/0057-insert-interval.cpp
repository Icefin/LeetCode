class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        for(const auto& interval : intervals){
            if(interval[1]<newInterval[0])
                res.push_back(interval);
            else if(newInterval[1]<interval[0]){
                res.push_back(newInterval);
                newInterval=interval;
            }
            else{
                newInterval[0]=min(newInterval[0],interval[0]);
                newInterval[1]=max(newInterval[1],interval[1]);
            }    
        }
        res.push_back(newInterval);
        return res;
    }
};