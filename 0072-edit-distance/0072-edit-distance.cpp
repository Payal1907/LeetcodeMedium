class Solution {
public:
    int dp[501][501];
    int helper(int i, int j, string& w1, string& w2){
        if(i==w1.size() && j==w2.size()) return 0;
        if(i==w1.size()) return w2.size()-j;
        if(j==w2.size()) return w1.size()-i; 
        if(w1[i]==w2[j]) return helper(i+1, j+1, w1, w2);
        if(dp[i][j]!=-1) return dp[i][j];
        int insertOp = 1 + helper(i,j+1, w1, w2);
        int deleteOp = 1 + helper(i+1,j,w1,w2);
        int replaceOp = 1 + helper(i+1,j+1,w1,w2);
        return dp[i][j]=min({insertOp,deleteOp,replaceOp});
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,word1,word2);
    }
};