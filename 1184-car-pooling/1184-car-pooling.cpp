class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxEnd=INT_MIN;
        for(int i=0;i<trips.size();i++)
        {
            maxEnd=max(maxEnd,trips[i][2]);
        }
        vector<int> diff(maxEnd+1,0);
        for(int i=0;i<trips.size();i++)
        {
            int start = trips[i][1];
            int end = trips[i][2];
            int val = trips[i][0];
            diff[start]+=val;
            diff[end]-=val;
        } 
        vector<int> res(maxEnd,0);
        res[0]=diff[0];
        for(int i=1;i<maxEnd;i++)
        {
            res[i]+=res[i-1]+diff[i];
        } 
        for(auto num : res)
        {
            if(num>capacity) return false;
        }
        return true;     
    }
};