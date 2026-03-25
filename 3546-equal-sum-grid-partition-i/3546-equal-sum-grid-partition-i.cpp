class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<long long> rsum(n,0),csum(m,0);
    long long tsum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            rsum[i]+=grid[i][j];
            csum[j]+=grid[i][j];
            tsum+=grid[i][j];
        }
    }
    for(int i=1;i<n;i++) rsum[i]+=rsum[i-1];
    for(int i=1;i<m;i++) csum[i]+=csum[i-1];

    for(int i=0;i<n;i++) if(tsum-rsum[i]==rsum[i]) return true;
    for(int i=0;i<m;i++) if(tsum-csum[i]==csum[i]) return true;
    return false;

    }
};