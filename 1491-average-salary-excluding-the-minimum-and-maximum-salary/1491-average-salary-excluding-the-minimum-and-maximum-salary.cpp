class Solution {
public:
    double average(vector<int>& salary) {
        int minSalary = INT_MAX;
        int maxSalary = INT_MIN;
        int sum = 0;
        for (auto s : salary) {
            sum += s;
            if (s > maxSalary) {
                maxSalary = s;
            }
            if (s < minSalary) {
                minSalary = s;
            }
        }
        sum -= (maxSalary + minSalary);
        return (double)sum / (salary.size() - 2);
    }
};