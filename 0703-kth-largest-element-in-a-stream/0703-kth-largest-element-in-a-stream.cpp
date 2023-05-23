class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        mk = k;
        
        for (int i = 0; i < nums.size(); i++) {
            mpq.push(nums[i]);
            
            if (mpq.size() > mk)
                mpq.pop();
        }
    }
    
    int add(int val) {
        mpq.push(val);
        
        if (mpq.size() > mk)
            mpq.pop();
        return mpq.top();
    }
    
private :
    int mk;
    priority_queue<int, vector<int>, greater<int>> mpq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */