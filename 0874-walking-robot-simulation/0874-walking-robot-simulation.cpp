class Solution {
private:
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, -1, 0, 1};
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        std::set<long long> s;
        for (int i = 0; i < obstacles.size(); ++i)
            s.insert((long long)obstacles[i][0] * 100000 + obstacles[i][1]);
        
        int res = 0;
        int x = 0, y = 0;
        int dir = 0;
        for (int i = 0; i < commands.size(); ++i) {
            if (commands[i] == -1) {
                dir--;
                dir = dir < 0 ? 3 : dir;
            }
            else if (commands[i] == -2) {
                dir++;
                dir = dir > 3 ? 0 : dir;
            }
            else {
                for (int j = 0; j < commands[i]; ++j) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
                    if (s.find((long long)nx * 100000 + ny) != s.end())
                        break;
                    
                    x = nx;
                    y = ny;
                }
                    
            }
            
            res = max(res, x * x + y * y);
        }
        return res;
    }
};