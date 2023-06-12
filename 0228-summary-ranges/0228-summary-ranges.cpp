class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) {
            return res;
        }
        int n = nums.size();
        int left = 0;
        int right = 0;
        for (; right < n - 1; right++) {
            if (nums[right + 1] == nums[right] + 1) {
                continue;
            }
            
            if (left == right) {
                res.push_back(to_string(nums[left]));
            }
            else {
                string temp = to_string(nums[left]) + "->" + to_string(nums[right]);
                res.push_back(temp);    
            }
            left = right + 1;
        }
        if (left == right) {
            res.push_back(to_string(nums[left]));
        }
        else if (left < right) {
            string temp = to_string(nums[left]) + "->" + to_string(nums[right]);
            res.push_back(temp);
        }
        return res;
    }
};