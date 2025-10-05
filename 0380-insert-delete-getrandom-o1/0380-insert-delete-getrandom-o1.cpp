class RandomizedSet {
private:
    vector<int> vals;
    unordered_map<int, int> valsMap;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valsMap.count(val)) return false;
        vals.push_back(val);
        valsMap[val] = vals.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!valsMap.count(val)) return false;

        int backNum = vals[vals.size() - 1];
        vals[valsMap[val]] = backNum;
        valsMap[backNum] = valsMap[val]; 
        vals.pop_back();

        valsMap.erase(val);
        return true;
    }
    
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */