class Solution {
public:
    int maxLength(vector<string>& arr) {
        res = 0;
        unordered_set<int> us;
        dfs(0, arr, us);
        return res;
    }
    
private :
    int res;
    void dfs(int idx, vector<string>& arr, unordered_set<int>& us) {
        if (idx == arr.size()) {
            res = res < us.size() ? us.size() : res;
            return;
        }
        
        vector<bool> alpha(26, false);
        bool isConcatable = true;
        for (int i = 0; i < arr[idx].length(); ++i) {
            if (us.find(arr[idx][i]) != us.end() || alpha[arr[idx][i] - 'a'] == true) {
                isConcatable = false;
                break;
            }
            alpha[arr[idx][i] - 'a'] = true;
        }
        
        if (isConcatable == true) {
            for (int i = 0; i < arr[idx].length(); ++i)
                us.insert(arr[idx][i]);
        }
        dfs(idx + 1, arr, us);
        if (isConcatable == true) {
            for (int i = 0; i < arr[idx].length(); ++i)
                us.erase(arr[idx][i]);
        }
        dfs(idx + 1, arr, us);
    }
};