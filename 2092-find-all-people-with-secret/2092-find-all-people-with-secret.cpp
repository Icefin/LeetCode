class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < meetings.size(); ++i) {
            int x = meetings[i][0];
            int y = meetings[i][1];
            int t = meetings[i][2];
            
            mp[t].emplace_back(x, y);
        }
        
        vector<bool> secrets(n, false);
        secrets[0] = true;
        secrets[firstPerson] = true;
        
        for (auto& [t, meetings] : mp) {
            unordered_map<int, vector<int>> meet;
            for (auto& [x, y] : meetings) {
                meet[x].push_back(y);
                meet[y].push_back(x);
            }
            
            unordered_set<int> start;
            for (auto& [x, y] : meetings) {
                if (secrets[x] == true)
                    start.insert(x);
                if (secrets[y] == true)
                    start.insert(y);
            }
            
            queue<int> q;
            for (auto& person : start)
                q.push(person);
            while (q.empty() == false) {
                int person = q.front(); q.pop();
                for (auto& next : meet[person]) {
                    if (secrets[next] == false) {
                        secrets[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (secrets[i] == true)
                res.push_back(i);
        }
        return res;
    }
};