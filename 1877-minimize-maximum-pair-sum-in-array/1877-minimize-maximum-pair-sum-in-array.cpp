class Solution {
public:
    // bool isPossible(vector<int>& nums, int mid){
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         if(nums[i]+nums[i+1]>mid) return false;
    //     }
    // }
    int minPairSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    // int low = *max_element(nums.begin(),nums.end());
    // int high = *accumulate(nums.begin(),nums.end(),0);
    int ans = -1;
    // while(low<=high){
    //     int mid = low+(high-low)/2;
    //     if(isPossible(nums,mid)){
    //         ans=mid;
    //         high=mid-1;
    //     }
    //     else low=mid+1;
    // }
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