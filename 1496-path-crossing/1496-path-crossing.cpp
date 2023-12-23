class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> ps;
        pair<int, int> curr = {0, 0};
        ps.insert(curr);
        for (char c : path) {
            if (c == 'N')
                curr.first++;
            else if (c == 'S')
                curr.first--;
            else if (c == 'E')
                curr.second++;
            else if (c == 'W')
                curr.second--;
            
            if (ps.find(curr) != ps.end())
                return true;
            ps.insert(curr);
        }
        return false;
    }
};