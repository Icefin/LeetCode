class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())
            return false;
        
        vector<int> v1(26, 0), v2(26, 0);
        vector<bool> v3(26, false), v4(26, false);
        
        for (int i = 0; i < word1.length(); ++i) {
            v1[word1[i] - 'a']++;
            v2[word2[i] - 'a']++;
            v3[word1[i] - 'a'] = true;
            v4[word2[i] - 'a'] = true;
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1 == v2 && v3 == v4;
    }
};