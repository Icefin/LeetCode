class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> res;
        for (int i = 0; i < currentState.length() - 1; ++i) {
            if (currentState[i] == '+' && currentState[i + 1] == '+') {
                std::string temp = currentState;
                temp[i] = '-';
                temp[i + 1] = '-';
                res.emplace_back(temp);
            }
        }
        return res;
    }
};