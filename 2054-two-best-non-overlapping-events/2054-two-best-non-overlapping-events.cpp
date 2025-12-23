class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    //end,val in min order
    sort(events.begin(),events.end());
    int ans = 0,maxi = 0;
    for(auto event : events)
    {
        int st = event[0];
        int end = event[1];
        int val = event[2];
        while(!pq.empty() && pq.top().first<st){
            maxi=max(maxi,pq.top().second);
            pq.pop();
        }
        ans=max(ans,maxi+val);
        pq.push({end,val});
    }   
    return ans;
    }
};