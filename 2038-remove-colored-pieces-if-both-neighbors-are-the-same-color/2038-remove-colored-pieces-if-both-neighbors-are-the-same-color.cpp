class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnt_a = 0, cnt_b = 0;
        int alice = 0, bob = 0;
        
        int n = colors.length();
        for (int i = 0; i < n; ++i) {
            if (colors[i] == 'A') {
                cnt_a++;
                cnt_b = 0;
            }
                
            else if (colors[i] == 'B') {
                cnt_b++;
                cnt_a = 0;
            }
                
            if (cnt_a >= 3)
                alice++;
            if (cnt_b >= 3)
                bob++;
        }
        return (alice > bob);
    }
};