class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int j = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (j < spaces.size() && i == spaces[j]) {
                res += " ";
                j++;
            }
            
            res += s[i];
        }
        
        return res;
    }
};