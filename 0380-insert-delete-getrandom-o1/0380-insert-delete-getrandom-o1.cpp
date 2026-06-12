class RandomizedSet {
public:
    unordered_set<int> st;
    vector<int> arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!st.count(val)){
            st.insert(val);
            arr.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(st.count(val)){
            st.erase(val);
            erase(arr,val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int rnd = rand()%arr.size();
        return arr[rnd];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */