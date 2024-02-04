class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if(n > m)
            return "";
        
        std::map<char, int> t_char;
        std::map<char, int> s_char;

        for (int i = 0; i < n; ++i)
            t_char[t[i]]++;

        int minLen = m + 1;
        int l = 0;
        int surplus = 0;
        string ret = "";
        for (int r = 0; r < m; ++r){
            if (t_char[s[r]] == 0){
                surplus++;
                continue;
            }

            if (t_char[s[r]] <= s_char[s[r]]){
                surplus++;
            }
            s_char[s[r]]++;

            if (r - l + 1 == n + surplus){
                while (true) {
                    if (t_char[s[l]] == 0){
                        surplus--;
                        l++;
                    }
                    else if (s_char[s[l]] > t_char[s[l]]){
                        s_char[s[l]]--;
                        surplus--;
                        l++;
                    }
                    else break;
                }

                if (r - l + 1 < minLen){
                    minLen = r - l + 1;
                    ret = s.substr(l, r - l + 1);
                }
            }
        }
        return ret;
    }
};