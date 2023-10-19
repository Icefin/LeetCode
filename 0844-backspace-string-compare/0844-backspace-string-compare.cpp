class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> ss, st;
        for (char c : s) {
            if (c == '#' && ss.empty() == false)
                ss.pop();
            else if (c != '#')
                ss.push(c);
        }
        
        for (char c : t) {
            if (c == '#' && st.empty() == false)
                st.pop();
            else if (c != '#')
                st.push(c);
        }
        
        while (ss.empty() == false && st.empty() == false) {
            if (ss.top() != st.top())
                return false;
            
            ss.pop();
            st.pop();
        }
        
        return (ss.empty() && st.empty());
    }
};