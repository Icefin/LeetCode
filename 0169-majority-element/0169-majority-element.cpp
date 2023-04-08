class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int ans = arr[0];
        int count = 0;
        for(int i = 0; i < arr.size(); i++){
            if(count==0) ans = arr[i];
            count += (ans == arr[i]) ? 1 : -1;
        }
        return ans;
    }
};