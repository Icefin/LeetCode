class MyHashSet {
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        if (findKeyIndex(key) != -1) {
            return;
        }
        vector<int>::iterator iter = lower_bound(v.begin(), v.end(), key);
        v.insert(iter, key);
        
    }
    
    void remove(int key) {
        if (findKeyIndex(key) == -1) {
            return;
        }
        vector<int>::iterator iter = lower_bound(v.begin(), v.end(), key);
        v.erase(iter);
    }
    
    bool contains(int key) {
        if (findKeyIndex(key) == -1) {
            return false;
        }
        return true;
    }
    
private :
    vector<int> v;
    int findKeyIndex(int key) {
        int left = 0, right = v.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[mid] == key) {
                return mid;
            }
            if (v[mid] > key) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */