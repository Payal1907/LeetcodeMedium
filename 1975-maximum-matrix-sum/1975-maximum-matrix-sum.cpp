class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg = 0;
        int mn = INT_MAX;
        long long sum = 0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                sum+=(long long)abs(matrix[i][j]);
                if(matrix[i][j]<0) neg++;
                mn=min(mn,abs(matrix[i][j]));
            }
        }
        return (neg%2==0)?sum:(sum-(long long)2*mn);
    }
};