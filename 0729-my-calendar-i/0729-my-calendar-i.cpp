class MyCalendar {
public:
    set<pair<int,int>> mp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime){
        bool acc = false;
        for(auto p : mp){
            int start = p.first;
            int end = p.second;
            if(endTime>start && startTime<end){ //overlap
                acc=true;
            }
        }
        if(acc) return false;
        else{
            mp.insert({startTime,endTime});
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */