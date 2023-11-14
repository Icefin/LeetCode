class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> um;
        
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
        
        int res = 0;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (um[s[i]] < um[s[i + 1]])
                res -= um[s[i]];
            else
                res += um[s[i]];
        }
        return res;
    }
};