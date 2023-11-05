class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (arr.size() <= k)
            return *(max_element(arr.begin(), arr.end()));
        
        queue<int> q;
        for (int i : arr)
            q.push(i);

        int cnt = 0;
        while (true) {
            int value = q.front(); q.pop();
            
            while (true) {
                if (cnt == k)
                    return (value);
                
                if (value < q.front()) {
                    q.push(value);
                    break ;
                }

                q.push(q.front()); q.pop();
                cnt++;
            }
            cnt = 1;
        }
    }
};