class Solution {
public:
    void dfs(int node, vector<vector<int>>& grid, vector<int>& vis){
        int n = grid.size();
        vis[node]=1;
        for(int neigh = 0;neigh<n;neigh++){
            if(grid[node][neigh]==1 && !vis[neigh]){
                dfs(neigh,grid,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> vis(n,0);
    int provinces = 0;
    for(int city = 0;city<n;city++){
        if(!vis[city]){
            provinces++;
            dfs(city,grid,vis);
        }
    }
    return provinces;
    }
};