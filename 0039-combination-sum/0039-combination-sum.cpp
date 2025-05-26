class Solution {
public:
    void func(int index, int target, vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, int n)
    {
        if(index==n)
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return; //ab smjh aaya return bahar kyu hai, kyuki index out of bound hua, aur ye condition meet bhi nahi hui, to inner if me daalegi to kaise accept krega
        }
        if(nums[index]<=target)
        {
            ds.push_back(nums[index]);
            func(index,target-nums[index],ds,nums,ans,n);
            ds.pop_back();
        }
        func(index+1,target,ds,nums,ans,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    int n=candidates.size();
    vector<int> ds;
    func(0,target,ds,candidates,ans,n);  
    return ans;  
    }
};