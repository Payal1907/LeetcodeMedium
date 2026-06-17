class Solution {
public:
    int helper(int index,int prev,int n,vector<int>&nums,vector<vector<int>>& tt){
        if(index==n) return 0;
        if(tt[index][prev+1]!=-1) return tt[index][prev+1];
        //not pick
        int np=0+helper(index+1,prev,n,nums,tt);
        //pick
        int p;
        if(prev==-1 || nums[index]>nums[prev]) p=1+helper(index+1,index,n,nums,tt);
        return tt[index][prev+1]=max(p,np);
    }
    int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> tt(n,vector<int>(n+1,-1));
    return helper(0,-1,n,nums,tt);
    }
};