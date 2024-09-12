class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        std::set<char> s;
        for (int i = 0; i < allowed.length(); ++i)
            s.insert(allowed[i]);
        
        int res = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            bool isAllowed = true;
            for (int j = 0; j < words[i].length(); ++j)
            {
                if (s.find(words[i][j]) == s.end())
                {
                    isAllowed = false;
                    break;
                }
            }
            
            if (isAllowed)
                res++;
        }
        return res;
    }
};