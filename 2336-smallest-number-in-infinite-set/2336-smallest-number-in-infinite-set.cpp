class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        idx = 1;
    }
    
    int popSmallest() {
        int res;
        if (pq.empty()) {
            res = idx;
            idx++;
            return res;
        }
        res = pq.top(); pq.pop();
        while(!pq.empty() && pq.top() == res)
            pq.pop();
        return res;
    }
    
    void addBack(int num) {
        if (num >= idx)
            return;
        pq.push(num);
    }
    
private :
    int idx;
    priority_queue<int, vector<int>, greater<int>> pq;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */