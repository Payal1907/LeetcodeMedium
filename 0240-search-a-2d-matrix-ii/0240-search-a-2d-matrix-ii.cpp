class Solution {
public:
//isko search matrix 1 ki trh nai kr skte kyuki, first element of each row is not equal to last 
//element of previous row

//dekh hm shuru krenge last col and first row se, kyuki col aur row dono increasing order me sorted hai, to agr target ki value matrix[row][col] se zyada hai to hm next row pe shift krenge kyuki ek row me last element hi sbse bda hai, otherwise hm ek col kam pe shift krenge
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m-1;
    while(row<n && col>=0)
    {
        if(matrix[row][col]==target) return true;
        else if(target>matrix[row][col]) row++; 
        else col--;
    }  
    return false;  
    }
};