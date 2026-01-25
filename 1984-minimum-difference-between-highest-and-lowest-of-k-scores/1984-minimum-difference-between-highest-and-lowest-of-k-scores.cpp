class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
    if(nums.size()==1) return 0;
    sort(nums.begin(),nums.end());
    int minimized = INT_MAX;
    for(int i=0;i<=nums.size()-k;i++){
        int mn = nums[i];
        int mx = nums[i+k-1];
        minimized = min(minimized, mx-mn);
    }  
    return minimized;
    }
};