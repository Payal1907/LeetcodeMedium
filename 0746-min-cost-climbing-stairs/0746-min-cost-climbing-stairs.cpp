class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    // vector<int> dp(n+1,0);
    // dp[0]=0;
    // dp[1]=0;
    // //no cost to start from here
    // for(int i=2;i<=n;i++){
    //     dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
    // } 
    // return dp[n]; 

    int step0 = 0;  
    int step1 = 0;
    int ans = 0;
    for(int i=2;i<=n;i++){
        ans = min(step0+cost[i-2],step1+cost[i-1]);
        step0=step1;
        step1=ans;
    }
    return ans;
    }
};