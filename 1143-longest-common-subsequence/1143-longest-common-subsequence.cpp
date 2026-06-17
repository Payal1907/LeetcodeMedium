class Solution {
public:
    int solve(int i, int j, string& text1, string& text2, int n, int m){
        if(i==n || j==m) return 0;
        if(text1[i]==text2[j]) return 1+solve(i+1,j+1,text1,text2,n,m);
        return max(solve(i+1,j,text1,text2,n,m), solve(i,j+1,text1,text2,n,m));   
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // return solve(0,0,text1,text2,n,m);
        vector<vector<int>> t(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) t[i][j]=1+t[i-1][j-1];
                else t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[n][m];   
    }
};