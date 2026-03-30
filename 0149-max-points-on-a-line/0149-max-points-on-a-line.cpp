class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
    //sbki slopes nikalenge, basically n lines so n*n cmobinations
    //max number of same slopes
    int ans = 1;
    int n = points.size();
    for(int i=0;i<n-1;i++){
        unordered_map<double,int> mp;
        int x1 = points[i][0];
        int y1 = points[i][1];
        for(int j=i+1;j<n;j++){
            int x2 = points[j][0];
            int y2 = points[j][1];
            double slope = (double)(y2-y1)/(double)(x2-x1);
            if(isinf(slope)) slope = INT_MAX; //all vertical - last case dekh
            if(slope==-0) slope=0;
            mp[slope]++;
        }
        int res = 0;
        for(auto it : mp){
            res=max(res,it.second+1);
        }
        ans=max(ans,res);
    }
    return ans;
    }
};