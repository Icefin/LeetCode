class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]){
                    vector<vector<bool>> check(m, vector<bool>(n, false));
                    if (search(board, word, check, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
    
private:
    bool search(const vector<vector<char>>& board, const string& word, vector<vector<bool>>& check, int r, int c, int idx) {
        if (idx == word.length()) return true;
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || check[r][c] ||  board[r][c] != word[idx])
            return false;

        check[r][c] = true;
        bool upSearch = search(board, word, check, r - 1, c, idx + 1);
        bool downSearch = search(board, word, check, r + 1, c, idx + 1);
        bool leftSearch = search(board, word, check, r, c - 1, idx + 1);
        bool rightSearch = search(board, word, check, r, c + 1, idx + 1);
        check[r][c] = false;
        return upSearch || downSearch || leftSearch || rightSearch;
    }
};