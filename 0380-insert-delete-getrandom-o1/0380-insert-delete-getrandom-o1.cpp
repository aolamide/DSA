class RandomizedSet {
private:
    unordered_map<int, int> mp;
    vector<int> vals;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        vals.push_back(val);
        mp[val] = vals.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        int removeIdx = mp[val];
        
        vals[removeIdx] = vals[vals.size() - 1];
        mp[vals[vals.size() - 1]] = removeIdx;
        vals.pop_back();
        mp.erase(val);
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