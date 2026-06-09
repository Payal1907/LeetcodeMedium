class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size();
        q.push({row,col});
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            //traverse negihbors and mark them
            //either all neighbors separately or use directions
            //-1 0 1
            //isme 4 directions is consider kr rhe
            for(int i=0;i<4;i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }

                }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>> vis(n,vector<int>(m,0));
       int cnt = 0;
       for(int row = 0;row<n;row++){
        for(int col =0;col<m;col++){
            if(!vis[row][col] && grid[row][col]=='1'){
                cnt++;
                bfs(row,col,vis,grid);
            }
        }
       }
       return cnt;
 
    }
};