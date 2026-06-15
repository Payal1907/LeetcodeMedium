class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int total = 0, count = 0, time = 0;
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,1,0,-1};
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=0) total++;
            if(grid[i][j]==2) q.push({i,j});
        }
    }  
    while(!q.empty()){
        int s = q.size();
        count+=s;
        while(s--){
        auto node = q.front();
        q.pop();
        int r = node.first;
        int c = node.second;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr<0 || nr>=n || nc<0 || nc>=m || grid[nr][nc]!=1) continue;
            grid[nr][nc]=2;
            q.push({nr,nc});
        }
        }
        if(!q.empty()) time++;
    }
    return (count==total)?time:-1;

    }
};