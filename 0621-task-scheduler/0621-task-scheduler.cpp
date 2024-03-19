class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0){
            return tasks.size();
        }

        int ret = 0;
        unordered_map<char, int> um_task;
        int cnt_max = 0;

        for (char task : tasks){
            um_task[task]++;
            cnt_max = max(cnt_max, um_task[task]);
        }

        ret = (cnt_max - 1)*(n + 1);
        for (auto pair : um_task){
            if (pair.second == cnt_max){
                ret++;
            }
        }
        
        return ret < tasks.size() ? tasks.size() : ret;
    }
};