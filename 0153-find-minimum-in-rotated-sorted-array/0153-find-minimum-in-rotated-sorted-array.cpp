class Solution {
public:
    int findMin(vector<int>& nums) {
     //the rotated part will always have the smallest element, bcoz if its were in sorted order it would have the smallest element
    int low =0;
    int high = nums.size()-1;
    int ans = INT_MAX;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[low]<=nums[mid])
        {
            ans=min(ans,nums[low]);
            low=mid+1;
        }
        else
        {
            ans=min(ans,nums[mid]);
            high=mid-1;
        }
    } 
    return ans;  
    }
};