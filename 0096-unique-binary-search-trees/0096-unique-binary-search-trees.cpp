class Solution {
public:
    // int solve(int n,vector<int>& dp){
    //     if(n<=1) return 1;
    //     int ans = 0;
    //     if(dp[n]!=-1) return dp[n];
    //     //ye root nodes hai
    //     for(int i=1;i<=n;i++){
    //         ans+=solve(i-1,dp)*solve(n-i,dp);
    //     }
    //     return dp[n]=ans;
    // }
    int numTrees(int n) {
        // if(n<=1) return 1;
        // int ans = 0;
        // //ye root nodes hai
        // for(int i=1;i<=n;i++){
        //     ans+=numTrees(i-1)*numTrees(n-i);
        // }
        // return ans;
        vector<int> dp(n+1,0);
        // return solve(n,dp);
        dp[0]=1;
        dp[1]=1;
        //number of nodes
        for(int i=2;i<=n;i++){
            //root nodes
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }     
        }
        return dp[n];
    }
};