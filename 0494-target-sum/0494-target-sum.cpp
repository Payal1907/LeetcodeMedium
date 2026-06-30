class Solution {
public:
    int cnt = 0;
    void solve(int index,int sum, vector<int>& nums, int target){
        if(index==nums.size()){
            if(sum==target) cnt++;
            return;
        }
        solve(index+1,sum+nums[index],nums,target);
        solve(index+1,sum-nums[index],nums,target);   
    }
    int findTargetSumWays(vector<int>& nums, int target) {
    //either add number or subtract number and count max of ans 
    
    solve(0,0,nums,target);
    return cnt;   
    }
};