class Solution {
public:
    int solve(int start,int end, vector<int>& nums,vector<int>& dp){
        if(start>end) return 0;
        if(dp[start]!=-1) return dp[start];
        int  p = nums[start]+solve(start+2,end,nums,dp);
        int np = solve(start+1,end,nums,dp);
        return dp[start]=max(p,np);

    }
    int rob(vector<int>& nums) {
    // 0 -> n-2
    // 1 -> n-1
    //aur inka max jo bhi hoga 
    int n = nums.size();
    if(n==1) return nums[0];
    vector<int> dp1(n,-1);
    vector<int> dp2(n,-1);
    int c1 = solve(0,n-2,nums,dp1);
    int c2 = solve(1,n-1,nums,dp2); 
    return max(c1,c2); 
    }
};