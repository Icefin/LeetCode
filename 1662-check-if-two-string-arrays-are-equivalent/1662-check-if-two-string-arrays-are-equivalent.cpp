class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "";
        for (string word : word1){
            str1 += word;
        }
        
        int idx = 0;
        for (string word : word2){
            for (int i = 0; i < word.length(); i++){
                if (str1[idx] != word[i])
                    return false;
                idx++;
            }
        }

        if (idx != str1.length())
            return false;
        return true;
    }
};