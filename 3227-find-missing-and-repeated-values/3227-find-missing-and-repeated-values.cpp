class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
    unordered_map<int,int> mp;
    vector<int> ans;
    int sum = (n*n)*(n*n+1)/2;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            mp[grid[i][j]]++;
            if(mp[grid[i][j]]==2) 
            {
                ans.push_back(grid[i][j]);
                grid[i][j]=0;
            }
            sum-=grid[i][j];
        }
    } 
    ans.push_back(sum);
    return ans;   
    }
};