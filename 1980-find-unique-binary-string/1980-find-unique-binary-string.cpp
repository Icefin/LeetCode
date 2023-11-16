class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int upper_max = pow(2, nums[0].length());
        
        vector<bool> bucket(upper_max, false);
        for (string num : nums)
            bucket[stoi(num, 0, 2)] = true;
        
        string res[16];
        for (int i = 0; i < upper_max; ++i) {
            if (bucket[i] == false) {
                res[0] = bitset<1>(i).to_string();
                res[1] = bitset<2>(i).to_string();
                res[2] = bitset<3>(i).to_string();
                res[3] = bitset<4>(i).to_string();
                res[4] = bitset<5>(i).to_string();
                res[5] = bitset<6>(i).to_string();
                res[6] = bitset<7>(i).to_string();
                res[7] = bitset<8>(i).to_string();
                res[8] = bitset<9>(i).to_string();
                res[9] = bitset<10>(i).to_string();
                res[10] = bitset<11>(i).to_string();
                res[11] = bitset<12>(i).to_string();
                res[12] = bitset<13>(i).to_string();
                res[13] = bitset<14>(i).to_string();
                res[14] = bitset<15>(i).to_string();
                res[15] = bitset<16>(i).to_string();
                break;
            }
        }
        return res[nums[0].length() - 1];
    }
};