class Solution {
public: 
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        // vector<vector<int>> grid(n,vector<int>(n,0));
        // for(auto& q : queries){
        //     int type=q[0],index=q[1],val=q[2];
        //     if(type==0){
        //         for(int i=0;i<n;i++){
        //             grid[index][i]=val;
        //         }
        //     }
        //     else{
        //         for(int j=0;j<n;j++){
        //             grid[j][index]=val;
        //         }
        //     }
        // }
        vector<bool> rows(n,false);
        vector<bool> cols(n,false);
        int row = 0, col = 0;
        long long sum = 0;
        for(int i=queries.size()-1;i>=0;i--){
            int type=queries[i][0],index=queries[i][1],val=queries[i][2];
            if(type==0 && !rows[index]){
                sum+=(long long)(n-col)*val;
                rows[index]=true;
                row++;
            }
            else if(type==1 && !cols[index]){
                sum+=(long long)(n-row)*val;
                cols[index]=true;
                col++;
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         sum+=grid[i][j];
        //     }
        // }
        return sum;

    }
};