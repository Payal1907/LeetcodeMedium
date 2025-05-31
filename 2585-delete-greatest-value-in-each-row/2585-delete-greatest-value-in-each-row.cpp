class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
    int ans = 0;
    for (auto& row : grid) 
    {
        sort(row.begin(), row.end());
    }
    for(int j = grid[0].size()-1;j>=0;j--)
    {
        int maxi = 0;
        for(int i=0;i<grid.size();i++)
        {
            maxi=max(maxi,grid[i][j]);
        }
        ans+=maxi;
    }
    return ans;    
    }
};