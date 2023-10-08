class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> customerMp;
    unordered_map<string, pair<int, int>> stationMp;
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        if(customerMp.count(id)) return;
        customerMp[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if(!customerMp.count(id)) return;
        
        auto [startStation, startTime] = customerMp[id];
        
        int timeTaken = t - startTime;
        
        string stationsKey = startStation + '-' + stationName;
        
        if(stationMp.count(stationsKey)) {
            stationMp[stationsKey].first += timeTaken;
            stationMp[stationsKey].second++;
        } else {
            stationMp[stationsKey] = {timeTaken , 1};
        }
        
        customerMp.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string stationsKey = startStation + '-' + endStation;
        auto [totalTime, totalRides] = stationMp[stationsKey];
        return (double) totalTime / totalRides;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */