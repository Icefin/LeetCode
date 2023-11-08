class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) 
            return (t != 1);
        int x_dist = abs(sx - fx);
        int y_dist = abs(sy - fy);
        
        int min_dist = x_dist < y_dist ? y_dist : x_dist;
        
        return (t >= min_dist);
    }
};