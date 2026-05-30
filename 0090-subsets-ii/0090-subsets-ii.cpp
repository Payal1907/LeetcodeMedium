class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void helper(int index, vector<int>& nums, vector<int> curr){
        if(index==nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        helper(index+1,nums,curr);
        curr.pop_back();
        int i = index+1;
        while(i<nums.size() && nums[i]==nums[index]) i++;
        helper(i,nums,curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {   
        sort(nums.begin(),nums.end());
        helper(0,nums,curr);
        return ans;
    }
};