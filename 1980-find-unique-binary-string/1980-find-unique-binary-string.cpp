class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> um;
        for (string num : nums)
            um.insert(stoi(num, 0, 2));
        
        int n = nums.size();
        for (int i = 0; i <= n; ++i) {
            if (um.find(i) == um.end()) {
                return bitset<16>(i).to_string().substr(16 - n);
            }
        }
        return "";
    }
};