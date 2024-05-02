class Solution {
public:
    int findMaxK(vector<int>& nums) {
        std::map<int, uint8_t> mp;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0)
                mp[-nums[i]] |= 1;
            else
                mp[nums[i]] |= 1 << 1;
        }
        
        for (auto iter = mp.rbegin(); iter != mp.rend(); ++iter)
            if (iter->second == 3)
                return iter->first;
        return -1;
    }
};