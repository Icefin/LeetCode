class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int bucket[26];
        
        memset(bucket, 0, sizeof(bucket));
        for (char c : chars)
            bucket[c - 'a']++;
        
        int res = 0;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            bool is_good = true;
            int cnt[26];
            memset(cnt, 0, sizeof(cnt));
            
            for (char c : words[i]) {
                int idx = c - 'a';
                cnt[idx]++;
                if (cnt[idx] > bucket[idx]) {
                    is_good = false;
                    break;
                }
            }
            if (is_good == true)
                res += words[i].length();
        }
        return res;
    }
};