class Solution {
public:    
    string frequencySort(string s) {
        unordered_map<char, int> um_s;
        for (int i = 0; i < s.length(); ++i) {
            um_s[s[i]]++;
        }

        map<int, vector<char>> m_freq;
        for (auto& pair : um_s){
            m_freq[pair.second].push_back(pair.first);
        }

        string ans = "";
        for (auto& pair : m_freq){
            for (int i = 0; i < pair.second.size(); ++i){
                ans.append(pair.first, pair.second[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};