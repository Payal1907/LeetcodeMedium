class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n<=1) return 1;
        int ans = 0;
        if(dp[n]!=-1) return dp[n];
        //ye root nodes hai
        for(int i=1;i<=n;i++){
            ans+=solve(i-1,dp)*solve(n-i,dp);
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        // if(n<=1) return 1;
        // int ans = 0;
        // //ye root nodes hai
        // for(int i=1;i<=n;i++){
        //     ans+=numTrees(i-1)*numTrees(n-i);
        // }
        // return ans;
        vector<int> dp(n+1,-1);
        return solve(n,dp);
        // dp[0]=1;
        // dp[1]=1;
        // for(int i=1;i<=n;i++){
        //     dp[i]=dp[i-1]*dp[n-i];
        // }
    }
};