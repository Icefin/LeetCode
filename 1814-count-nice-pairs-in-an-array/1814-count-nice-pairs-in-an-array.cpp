class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        constexpr long modulo = 1e9 + 7;
        unordered_map<int, long> um;
        for (int num : nums) {
            int revNum = reverseDigits(num);
            um[num - revNum]++;
        }
        
        long res = 0;
        for (auto& elem : um) {
            res = (res + elem.second * (elem.second - 1) / 2) % modulo;
        }
        return res;
    }
    
private :
    int reverseDigits(int num) { 
        int revNum = 0; 
        while (num > 0) { 
            revNum = revNum * 10 + num % 10; 
            num = num / 10; 
        } 
        return revNum; 
    } 
};

