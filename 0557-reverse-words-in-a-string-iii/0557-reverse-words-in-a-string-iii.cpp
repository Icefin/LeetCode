class Solution {
public:
    string reverseWords(string s) {
        vector<string> sp = split(s, ' ');
        
        int n = sp.size();
        for (int i = 0; i < n; ++i)
            reverse(sp[i].begin(), sp[i].end());
        
        string res = "";
        for (int i = 0; i < n - 1; i++)
            res += (sp[i] + " ");
        res += sp.back();
        return res;
    }
    
private :
    vector<string> split(string input, char delimiter) {
        vector<string> res;
        stringstream ss(input);
        string temp;
 
        while (getline(ss, temp, delimiter))
            res.push_back(temp);
 
    return res;
}
};