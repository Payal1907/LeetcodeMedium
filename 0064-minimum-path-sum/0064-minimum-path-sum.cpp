class Solution {
public:
    int solve(int i,int j, vector<vector<int>>& grid,int n,int m,vector<vector<int>>& tt){
        if(i>=n||j>=m) return INT_MAX;
        if(i==n-1&&j==m-1) return grid[i][j];
        if(tt[i][j]!=-1) return tt[i][j];
        int right = solve(i,j+1,grid,n,m,tt);
        int down = solve(i+1,j,grid,n,m,tt);
        return tt[i][j]=grid[i][j]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> tt(n+1,vector<int>(m+1,-1));
        return solve(0,0,grid,n,m,tt);    
    }
};