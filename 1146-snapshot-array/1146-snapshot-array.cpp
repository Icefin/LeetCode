class SnapshotArray {
public:
    SnapshotArray(int length) {
        s_id = 0;
        records = vector<map<int, int>>(length);
        for (int i = 0; i < length; i++) {
            records[i][0] = 0;
        }
    }
    
    void set(int index, int val) {
        records[index][s_id] = val;
    }
    
    int snap() {
        return s_id++;
    }
    
    int get(int index, int snap_id) {
        if (records[index].find(snap_id) != records[index].end()) {
            return records[index][snap_id];
        }
        
        auto iter = --records[index].lower_bound(snap_id);
        return iter->second;
    }
    
private :
    int s_id;
    vector<map<int, int>> records;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */