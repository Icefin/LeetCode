class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int prev = nums[0];
        int currFrequency = 1;
        int maxFrequency = 1;
        int totalFrequency = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == prev) {
                currFrequency++;
            }
            else {
                prev = nums[i];
                currFrequency = 1;
            }
            
            if (currFrequency == maxFrequency) {
                totalFrequency += maxFrequency;
            }
            else if (currFrequency > maxFrequency) {
                totalFrequency = currFrequency;
                maxFrequency = currFrequency;
            }
        }
        
        return totalFrequency;
    }
};