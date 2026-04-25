class Solution {
public:
    int solve(vector<vector<int>>& nums, int i,int j,vector<vector<int>>& memo)
    {
        if(i<0||j<0||nums[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(memo[i][j]!=-1) return memo[i][j];
        int a = solve(nums,i-1,j,memo);
        int b = solve(nums,i,j-1,memo);
        memo[i][j]=a+b;
        return memo[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solve(obstacleGrid,m-1,n-1,memo);
    }
};