class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length()) return false;
        if (s == "") return true;
        int ptr = 0;

        for (int i = 0; i < t.length(); i++) {
            if (s[ptr] == t[i]) ptr++;
            if (ptr == s.length()) return true;
        }
        return false;
    }
};

//Follow up!!
//k >= 10^9
//t.length <= 10^4
//Worst Case -> k*len => 10^13 // 10,000,000,000,000 
//Time Complexity : O(k*t.length) //

//What about Dictionarize??
//From t, make all possible subsequences...
//then, make dictionary from those subsequences and compare with s array
//How many time we should take to make possible subsequences from t??
//Worst Case -> 2^(10^4) -> 16^10 // 1,099,511,627,776
//Time Complexity : O(2^(t.length) + k)