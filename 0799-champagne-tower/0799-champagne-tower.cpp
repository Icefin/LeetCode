class Solution {
public:
    double champagneTower(int poured, int qi, int qj) {
        vector<vector<double>> tower(101, vector<double>(101, 0));

        tower[0][0] = poured;
        for (int i = 0; i <= qi; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (tower[i][j] > 1.0)
                {
                    if (i <= 99 && j <= i)
                    {
                        tower[i + 1][j] += (tower[i][j] - 1.0) / 2.0;
                        tower[i + 1][j + 1] += (tower[i][j] - 1.0) / 2.0;    
                    }
                    tower[i][j] = 1.0;
                }
            }
        }
        return tower[qi][qj];
    }
};