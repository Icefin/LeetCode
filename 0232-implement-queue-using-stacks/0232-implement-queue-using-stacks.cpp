class MyQueue {
public:
    MyQueue() {
        st = stack<int>();
    }
    
    void push(int x) {
        std::stack<int> temp;
        while (st.empty() == false) {
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while (temp.empty() == false) {
            st.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int value = st.top(); st.pop();
        return value;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
    
private: 
    std::stack<int> st;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */