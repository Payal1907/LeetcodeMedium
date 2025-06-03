class Solution {
public:
    void func(int index, vector<int> subset,vector<vector<int>>& ans,vector<int> nums, int n)
    {
        ans.push_back(subset);
        for(int i=index;i<n;i++)
        {
            if(i>index && nums[i]==nums[i-1]) continue;
            subset.push_back(nums[i]);
            func(i+1,subset,ans,nums,n);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    func(0,{},ans,nums,n);
    return ans;    
    }
};