class RandomizedSet {
public:
    RandomizedSet() {
        um = unordered_map<int, int>();
        v = vector<int>();
    }
    
    bool insert(int val) {
        if ((um.find(val) != um.end()) && (um[val] != -1))
            return false;
        um[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (v.empty() == true)
            return false;
        if ((um.find(val) == um.end()) || (um[val] == -1))
            return false;
        int eidx = um[val];
        v[eidx] = v.back();
        um[v.back()] = eidx;
        v.pop_back();
        um[val] = -1;
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
    
private :
    unordered_map<int, int> um;
    vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */