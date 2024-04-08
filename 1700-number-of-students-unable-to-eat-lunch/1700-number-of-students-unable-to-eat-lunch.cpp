class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue<int> q;
        for (const int i : students)
            q.push(i);
        
        for (int i = 0; i < sandwiches.size(); ++i) {
            bool isMatched = false;
            int cnt = q.size();
            for (int j = 0; j < cnt; ++j) {
                int front = q.front(); q.pop();
                if (front == sandwiches[i]) {
                    isMatched = true;
                    break;
                }
                q.push(front);
            }
            if (isMatched == false)
                return sandwiches.size() - i;
        }
        return 0;
    }
};