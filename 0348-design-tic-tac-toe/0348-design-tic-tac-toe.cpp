class TicTacToe {
public:
    TicTacToe(int n) : size(n) {
        p1 = vector<vector<int>>(2, vector<int>(n, 0));
        p1UR = 0, p1DR = 0;
        p2 = vector<vector<int>>(2, vector<int>(n, 0));
        p2UR = 0, p2DR = 0;
    }
    
    int move(int row, int col, int player) {
        if (player == 1) {
            p1[0][row]++;
            p1[1][col]++;
            if (row == col)
                p1UR++;
            if (row + col == size - 1)
                p1DR++;
        }
        else if (player == 2) {
            p2[0][row]++;
            p2[1][col]++;
            if (row == col)
                p2UR++;
            if (row + col == size - 1)
                p2DR++;
        }
        return checkGameState(player);
    }
    
private :
    int size;
    vector<vector<int>> p1;
    int p1UR, p1DR;
    vector<vector<int>> p2;
    int p2UR, p2DR;
    
    int checkGameState(int player) {
        if (player == 1) {
            for (int i = 0; i < size; i++) {
                if ((p1[0][i] == size) || (p1[1][i] == size)) {
                    return 1;
                }
            }
            if (p1UR == size || p1DR == size)
                return 1;
        }
        else if (player == 2) {
            for (int i = 0; i < size; i++) {
                if ((p2[0][i] == size) || (p2[1][i] == size)) {
                    return 2;
                }
            }
            if (p2UR == size || p2DR == size)
                return 2;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */