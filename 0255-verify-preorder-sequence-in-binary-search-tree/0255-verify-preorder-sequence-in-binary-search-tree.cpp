class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int minElem = INT_MIN;
        vector<int> st;
        
        for(int elem : preorder) {
            if(elem < minElem)
                return false;
            while(st.size() && st.back() < elem) {
                minElem = st.back();
                st.pop_back();
            }
            st.push_back(elem);
        }
        return true;
    }
};