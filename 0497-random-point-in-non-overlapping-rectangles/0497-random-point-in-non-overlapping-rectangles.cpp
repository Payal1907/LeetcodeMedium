class Solution {
public:
    vector<vector<int>> rect;
    vector<int> prefix;
    Solution(vector<vector<int>>& rects) {
        rect=rects;
        for(vector<int> v : rect){
            int len = v[2]-v[0]+1;
            int wid = v[3]-v[1]+1;
            int total = len*wid;
            prefix.push_back(((prefix.size()>0)?prefix.back():0) + total);
        }
    }  
    vector<int> pick() {
        int totalint = prefix.back();
        int randN = rand()%totalint;
        auto it = upper_bound(prefix.begin(),prefix.end(),randN);
        int index = it-prefix.begin();
        vector<int> v2 = rect[index];
        int x = rand()%(v2[2]-v2[0]+1) + v2[0];
        int y = rand()%(v2[3]-v2[1]+1) + v2[1];
        return {x,y};        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */