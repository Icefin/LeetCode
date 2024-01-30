class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& token : tokens) {
            if (token == "+") {
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                st.push(op2 + op1);
            }
            else if (token == "-") {
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                st.push(op2 - op1);
            }
            else if (token == "*") {
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                st.push(op2 * op1);
            }
            else if (token == "/"){
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                st.push(op2 / op1);
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};