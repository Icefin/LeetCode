class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty() == true)
            return vector<string>();
        vector<string> ans;
        string combination;
        combination.resize(digits.length());
        findAlphabetCombination(digits, 0, combination, ans);
        return ans;
    }
private :
    void findAlphabetCombination(const string& digits, int idx, string& combination, vector<string>& out_ans)
    {
        if (idx == digits.length())
        {
            out_ans.push_back(combination);
            return;
        }
        
        int num = digits[idx] - '0';
        for (int i = 0; i < digitToAlpha[num].length(); ++i)
        {
            combination[idx] = digitToAlpha[num][i];
            findAlphabetCombination(digits, idx + 1, combination, out_ans);
        }
    }

private :
    string digitToAlpha[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
};