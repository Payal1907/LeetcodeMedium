class FrontMiddleBackQueue {
public:
    vector<int> nums;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
    nums.insert(nums.begin(),val);
    }
    
    void pushMiddle(int val) {
    nums.insert(nums.begin()+(nums.size()/2),val);
        
    }
    
    void pushBack(int val) {
        nums.push_back(val);
        
    }
    
    int popFront() {
        if(nums.size()==0) return -1;
        int val = nums[0];
        nums.erase(nums.begin());
        return val;  
    }
    
    int popMiddle() {
        if(nums.size()==0) return -1;
        int val = nums[(nums.size()-1)/2];
        nums.erase(nums.begin()+(nums.size()-1)/2);
        return val;
        
    }
    
    int popBack() {
        if(nums.size()==0) return -1;
        int val = nums[nums.size()-1];
        nums.pop_back();
        return val;
        
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */