class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    if(n==0 || m==0) return false;
    if(n==1 && m==1) return true;
    long long tsum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tsum+=grid[i][j];
        }
    }
    long long rsum = 0;
    for(int i=0;i<n-1;i++){
        rsum+=accumulate(grid[i].begin(),grid[i].end(),0LL);
        if(tsum-rsum==rsum) return true;
    } 
    long long csum = 0;  
    for(int j=0;j<m-1;j++){
        long long col = 0;
        for(int i=0;i<n;i++){
            col+=grid[i][j];
        }
        csum+=col;
        if(tsum-csum==csum) return true;
    }
    return false;
    }
};