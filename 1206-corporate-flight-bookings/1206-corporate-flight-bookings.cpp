class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1,0);
        for(int i=0;i<bookings.size();i++)
        { 
            diff[bookings[i][0]-1]+=+bookings[i][2]; //diff[start-1]+=val
            diff[bookings[i][1]]-=+bookings[i][2]; //diff[end]-=val
        } 
        vector<int> res(n,0);
        res[0]=diff[0];
        for(int i=1;i<n;i++)
        {
            res[i]=res[i-1]+diff[i];
        }
        return res;
  
    }
};