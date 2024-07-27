class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val) == m.end()) {
            v.push_back(val);
            m[val] = v.size() - 1;
            return true;
        }
        
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()) {
            return false;
        }
        int x = m.find(val)->second;
        v[x] = v.back();
        v.pop_back();
        m[v[x]] = x;
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
private:
    unordered_map<int, int> m;
    vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */