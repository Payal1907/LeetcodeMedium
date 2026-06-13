class Solution {
public:

    int minPairSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int ans = -1;
    int left = 0, right = n-1;
    while(left<right){
        int curr = nums[left]+nums[right];
        ans=max(ans,curr);
        left++;
        right--;
    }
    return ans;
    }
};