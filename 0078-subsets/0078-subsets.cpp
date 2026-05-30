class Solution {
public:
    vector<vector<int>> ans;
    void helper(int index, vector<int> curr, vector<int>& nums){
        if(index==nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        helper(index+1,curr,nums);
        curr.pop_back();
        helper(index+1,curr,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        helper(0,curr,nums);
        return ans;
        
    }
};