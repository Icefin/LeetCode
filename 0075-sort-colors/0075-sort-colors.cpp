class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::array<int, 3> bucket = {0, 0, 0};
        
        for(int i = 0; i < nums.size(); ++i) {
            bucket[nums[i]]++;
        }
        
        int k = 0;
        for(int i = 0; i < nums.size(); ++i) {
            while(bucket[k] == 0)
                k++;
            nums[i] = k;
            bucket[k]--;
        }
    }
};