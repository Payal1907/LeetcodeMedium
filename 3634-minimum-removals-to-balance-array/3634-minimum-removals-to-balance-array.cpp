class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int n = nums.size();
        int j = 0;
        int ans = 0;
        while(j<n){
        while((long long)nums[j]>(long long)nums[i]*k){
            i++;
        }
        j++;
        ans=max(ans,j-i);
        }
        return n-ans; 
    }
};