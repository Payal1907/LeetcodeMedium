class Solution {
public:
    bool valid(int i,int j,vector<vector<int>>& grid)
    {
        vector<int> count(10,0);
        for(int l = 0;l<3;l++)
        {
            for(int m=0;m<3;m++)
            {
                int num = grid[i+l][j+m];
                if(num<1||num>9||count[num]>0) return false;
                count[num]++;
            }
        } 
        int sum = grid[i][j]+grid[i][j+1]+grid[i][j+2];
        for(int l=0;l<3;l++)
        {
            if(sum!=grid[i+l][j]+grid[i+l][j+1]+grid[i+l][j+2]) return false;
        }
        for(int l=0;l<3;l++)
        {
            if(sum!=grid[i][j+l]+grid[i+1][j+l]+grid[i+2][j+l]) return false;
        }
        if(sum!=(grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2])) return false;
        if(sum != (grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2])) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
      int ans = 0;
      int rows = grid.size();
      int cols = grid[0].size();
      if(rows<3 || cols<3) return 0;
      for(int i=0;i<=rows-3;i++)
      {
        for(int j=0;j<=cols-3;j++)
        {
            if(valid(i,j,grid)) ans++;
        }
      } 
      return ans; 
    }
};