class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int res = 1e9;
        int left = -1, right = -1;
        
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) {
                right = i;
                if (left != -1) {
                    int dist = right - left;
                    if (res > dist) res = dist;
                }
                if (word1 == word2)
                    left = right;
            }
            else if (wordsDict[i] == word2) {
                left = i;
                if (right != -1) {
                    int dist = left - right;
                    if (res > dist) res = dist;
                }
            }
        }
        return res;
    }
};