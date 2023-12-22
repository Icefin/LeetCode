class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0;
        
        set<char> uniq;
        map<char, int> mp;
        
        int res = 0;
        int len = s.length();
        for (int r = 0; r < len; ++r) {
            uniq.insert(s[r]);
            mp[s[r]]++;
            
            while (uniq.size() > 2) {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    uniq.erase(s[l]);
                l++;
            }
            
            res = max(res, r - l + 1);
        }
        return res;
    }
};