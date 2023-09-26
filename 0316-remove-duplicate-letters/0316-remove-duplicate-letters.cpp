class Solution {
public:
    string removeDuplicateLetters(string s) {
        int alpha[26];
        bool is_visited[26];
        
        memset(alpha, 0, sizeof(alpha));
        memset(is_visited, false, sizeof(is_visited));
        for(char c : s)
            alpha[c - 'a']++;

        string res;
        int n = s.length();
        for(int i = 0; i < n; ++i) {
            alpha[s[i] - 'a']--;
            if(is_visited[s[i] - 'a'] == false) { 
                while(res.empty() == false && res.back() > s[i] && alpha[res.back()-'a'] > 0) {
                    is_visited[res.back()-'a'] = false;
                    res.pop_back();
                }
                res.push_back(s[i]);
                is_visited[s[i]-'a'] = true;
            }
        }
        
        return res;
    }
};