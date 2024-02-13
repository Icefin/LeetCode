class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        
        for (int i = 0; i < n; ++i) {
            if (isPalindrome(words[i]) == true)
                return words[i];
        }
        return "";
    }
    
private:
    bool isPalindrome(const std::string& word) {
        int len = word.length();
        int half = len / 2;
        
        for (int i = 0; i < half; ++i) {
            if (word[i] != word[len - 1 - i])
                return false;
        }
        return true;
    }
};