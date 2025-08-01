class Solution {
public:
    vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1,1);
    long long ans =1;
    for (int i = 1; i < rowIndex; i++) {
        ans = ans*(rowIndex+1-i);
        ans=ans/i;
        row[i]=ans;
    }
    return row;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for(int i=0;i<numRows;i++)
        {
            pascal.push_back(getRow(i));
        }
        return pascal;
        
    }
};