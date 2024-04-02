class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> um_s;
		unordered_map<char, char> um_t;

		for (int i = 0; i < s.length(); ++i) {
			if (um_s.find(s[i]) == um_s.end() && um_t.find(t[i]) == um_t.end()) {
				um_s[s[i]] = t[i];
				um_t[t[i]] = s[i];
				continue;
			}

			if (um_s[s[i]] != t[i] || um_t[t[i]] != s[i])
                return false;
		}
		return true;
    }
};