class Solution {
public:
    bool find132pattern(vector<int>& nums) {
	    vector<int> min_arr(nums.size());
	    priority_queue<int, vector<int>, greater<int>> pq;
	    min_arr[0] = nums[0];
	    for (int i = 1; i < min_arr.size(); i++)
		    min_arr[i] = min_arr[i - 1] < nums[i] ? min_arr[i - 1] : nums[i];

	    for (int i = nums.size() - 1; i >= 0; --i) {
		    while (!pq.empty() && pq.top() <= min_arr[i]) pq.pop();


		    if (!pq.empty() && pq.top() < nums[i]) return true;
		
		    pq.push(nums[i]);
	    }
        
	    return false;
    }
};