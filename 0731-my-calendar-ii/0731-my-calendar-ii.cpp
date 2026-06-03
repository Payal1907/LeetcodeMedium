class MyCalendarTwo {
public:
    set<pair<int,int>> mp1;
    set<pair<int,int>> mp2;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto p : mp2){
            int start = p.first;
            int end = p.second;
            if(start<endTime && end>startTime){
                return false;
            }
        }
        for(auto p : mp1){
            int start = p.first;
            int end = p.second;
            if(start<endTime && end>startTime){
                mp2.insert({max(startTime,start),min(end,endTime)});
            }
        }
        mp1.insert({startTime,endTime});
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */