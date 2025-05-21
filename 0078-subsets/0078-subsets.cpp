class Solution {
public:
    void func(int index,vector<int> subset,vector<vector<int>>& ans, vector<int> nums,int n)
    {
        if(index==n)
        {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        func(index+1,subset,ans,nums,n);
        subset.pop_back();
        func(index+1,subset,ans,nums,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    func(0,{},ans,nums,n);
    return ans;
    
    }
};