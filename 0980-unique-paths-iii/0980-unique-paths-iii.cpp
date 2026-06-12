class Solution {
public:
    int ans =0 , emp = 0, sx,sy;
    void solve(int x, int y, vector<vector<int>>& grid, int cnt){
        int n =grid.size(),m=grid[0].size();
        if(grid[x][y]==2 && cnt==emp){
            ans++;
            return;
        }
        int temp = grid[x][y];
        grid[x][y]=-1; //visited
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!=-1){
                solve(nx,ny,grid,cnt+1);
            }
        }
        grid[x][y]=temp; //not visited again

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=-1) emp++;
            if(grid[i][j]==1){
                sx=i;
                sy=j;
            }
        }
    }
    solve(sx,sy,grid,1);
    return ans;
    }
};