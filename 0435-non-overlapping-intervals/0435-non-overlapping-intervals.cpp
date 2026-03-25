class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto& a,auto& b){return a[1]<b[1];});
        int end = intervals[0][1]; //preceding ka end time
        for(int i=1;i<n;i++){
            if(intervals[i][0]<end) cnt++; //curr ka start pichle wale ke end se kam hai to 
            else end=intervals[i][1];
        }   
        return cnt;
    }
};