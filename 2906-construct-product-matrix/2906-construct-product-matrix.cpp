class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    long long prefix = 1, suffix=1;
    vector<vector<int>> ans(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        ans[i][j]=prefix; //excpet the element so first we set value and then mulitply by the number
        prefix=prefix*grid[i][j]%12345;
        }
    }  
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            ans[i][j]=ans[i][j]*suffix%12345; //similarly yaha pe bhi
            suffix=suffix*grid[i][j]%12345;
        }
    }
    return ans;
    }
};