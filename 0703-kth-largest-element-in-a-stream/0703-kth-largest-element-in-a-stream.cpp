class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        mk = k;
        mstream = vector<int>(k < nums.size() ? k : nums.size());
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < k && i < nums.size(); i++) {
            mstream[i] = nums[i];
        }
    }
    
    int add(int val) {
        if (mstream.size() < mk) {
            mstream.push_back(val);
            sort(mstream.begin(), mstream.end(), greater<int>());
            return mstream.back();
        }
        
        if (val < mstream.back()) {
            return mstream.back();
        }
        
        int ptr = 0;
        for (; ptr < mstream.size(); ptr++) {
            if (val >= mstream[ptr]) {
                break;
            }
        }
        
        int prev = mstream[ptr];
        mstream[ptr] = val;
        ptr++;
        for (; ptr < mstream.size(); ptr++) {
            int temp = mstream[ptr];
            mstream[ptr] = prev;
            prev = temp;
        }
        return mstream.back();
    }
    
private :
    int mk;
    vector<int> mstream;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */