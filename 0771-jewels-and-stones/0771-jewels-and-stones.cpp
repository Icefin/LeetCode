class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        unordered_map<char, bool> um;
        for (auto jewel : jewels)
            um[jewel] = true;
        for (auto stone : stones) {
            if (um[stone])
                res++;
        }
        return res;
    }
};