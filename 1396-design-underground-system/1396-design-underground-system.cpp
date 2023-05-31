class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        um_id[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string prevStation = um_id[id].first;
        int checkInTime = um_id[id].second;
        um_id.erase(id);
        
        string key = prevStation + "#" + stationName;
        int timeSpan = t - checkInTime;
        um_time[key].first += timeSpan;
        um_time[key].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "#" + endStation;
        int totalTime = um_time[key].first;
        int totalCustomer = um_time[key].second;
        return (double)totalTime / totalCustomer;
    }
    
private :
    unordered_map<int, pair<string, int>> um_id;
    unordered_map<string, pair<int, int>> um_time;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */