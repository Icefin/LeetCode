class Solution {
public:
    string largestGoodInteger(string num) {
        int digit = -1;
        map<char, int> mp;
        
        for (int i = 0; i < 2; ++i)
            mp[num[i]]++;
        
        int l = 0, n = num.size();
        for (int i = 2; i < n; ++i) {
            mp[num[i]]++;
            if (mp.size() == 1) {
                if (mp.begin()->first - '0' > digit)
                    digit = mp.begin()->first - '0';
            }
            mp[num[l]]--;
            if (mp[num[l]] == 0)
                mp.erase(num[l]);
            l++;
        }
        
        if (digit == -1)
            return "";
        string res(3, '0' + digit);
        return res;
    }
};