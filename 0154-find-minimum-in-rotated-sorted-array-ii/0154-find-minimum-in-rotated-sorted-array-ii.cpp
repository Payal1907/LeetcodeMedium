class Solution {
public:
    int findMin(vector<int>& nums) {
    int low = 0;
    int high = nums.size()-1;
    int ans = INT_MAX;
    while(low<high)
    {
        int mid = low+(high-low)/2;
        if(nums[mid]>nums[high]) //min right half me milega
        {
            low=mid+1;
        }
        else if(nums[mid]<nums[high]) //min left half me milega jo mid bhi ho skta hai
        {
            high=mid;
        }
        else high--;
    }
    return nums[low];   
    }
};