class NumberContainers {
private:
    unordered_map<int, int> indexToNumMap;
    unordered_map<int, set<int>> numToIndexesMap;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexToNumMap.count(index)) {
            numToIndexesMap[indexToNumMap[index]].erase(index);
        }
        indexToNumMap[index] = number;
        numToIndexesMap[number].insert(index);
    }
    
    int find(int number) {
        if(!numToIndexesMap.count(number) || !numToIndexesMap[number].size()) return -1;
        return *(numToIndexesMap[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */