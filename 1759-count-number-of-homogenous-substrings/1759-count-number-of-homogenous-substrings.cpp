class Solution {
public:
    int countHomogenous(string s) {
        int res = 0;
        char prev = s[0];
        int cont = 1;
        
        int n = s.length();
        long long mod = (1e9 + 7);
        for (int i = 1; i < n; ++i) {
            if (s[i] != prev) {
                res += get_homogeneous_cnt(cont) % mod;
                cont = 1;
                prev = s[i];
                continue;
            }
            cont++;
        }
        res += get_homogeneous_cnt(cont) % mod;
        return (res);
    }

private :
    long long get_homogeneous_cnt(long long num) {
        return (num * (num + 1) / 2);
    }
};