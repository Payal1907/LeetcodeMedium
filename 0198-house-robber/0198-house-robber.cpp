class Solution {
public:
    int solve(vector<int>& nums, int i)
    {
        if(i>=nums.size()) return 0;
        int np = solve(nums,i+1);
        int p = solve(nums,i+2)+nums[i];
        return max(p,np);
    }
    int rob(vector<int>& nums) {
        return solve(nums,0);
    }
};