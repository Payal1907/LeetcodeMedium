class Solution {
public:
    //variables are i and j
    int t[51][51];

    //TC= O(n^3)
    //SC= O(n^2)
    int solve(vector<int>& nums,int i,int j)
    {
        if(j-i+1<3) return 0; //min teen sides chahiye
        if(t[i][j]!=-1) return t[i][j];
        int res = INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            int wt = nums[i]*nums[j]*nums[k]+solve(nums,i,k)+solve(nums,k,j);
            res=min(res,wt);
        }
        //return t[i][j]=res;
        t[i][j]=res;
        return res;
        //OR
        //t[i][j]=res
        //return t[i][j] OR return res;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(t,-1,sizeof(t));
        return solve(values,0,n-1);   
    }
};