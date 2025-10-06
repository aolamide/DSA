class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkIns;
    unordered_map<string, pair<int, int>> stationsTripMap;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = { stationName, t };
    }
    
    void checkOut(int id, string stationName, int t) {
        string stationStr = checkIns[id].first + "->" + stationName;
        stationsTripMap[stationStr].first += (t - checkIns[id].second);
        stationsTripMap[stationStr].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)(stationsTripMap[startStation + "->" + endStation].first) / (double)(stationsTripMap[startStation + "->" + endStation].second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */