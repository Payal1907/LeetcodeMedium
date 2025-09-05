class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int t = grid.size(), b = -1, l = grid[0].size(), r = -1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    t=min(t,i);
                    b=max(b,i);
                    l=min(l,j);
                    r=max(r,j);
                }
            }
        }
        if(b==-1) return -1; //there are no grids in box
        return (b-t+1)*(r-l+1);
        
    }
};