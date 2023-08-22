class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        convert(columnNumber, res);
        return res;
    }

private :
    void convert(int number, string& out) {
        number--;
        if (number < 26)
            out += alphaMap[number];
        else {
            convert(number / 26, out);
            out += alphaMap[number % 26];
        }
    }
    
    char alphaMap[26] = {
        'A', 'B', 'C', 'D', 'E',
        'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O',
        'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y',
        'Z'
        };
};