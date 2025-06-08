class Solution {
public:
    int binarySearch(vector<int>& row,int low,int high, int target)
    {
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(row[mid]==target) return mid;
            else if(target<row[mid]) high=mid-1;
            else low=mid+1; 
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++)
        {
            vector<int> row = matrix[i];
            int index = binarySearch(row,0,matrix[i].size()-1,target);
            if(index!=-1) return true;
        }
        return false; 

    }
};