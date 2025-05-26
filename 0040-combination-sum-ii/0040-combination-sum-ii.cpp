class Solution {
public:
    void func(int index, int target, vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, int n)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<n;i++)
        {
            if(i>index && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            ds.push_back(nums[i]);
            func(i+1,target-nums[i],ds,nums,ans,n);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    sort(candidates.begin(),candidates.end());
    int n=candidates.size();
    vector<int> ds;
    func(0,target,ds,candidates,ans,n); 
    return ans;    
    }
};