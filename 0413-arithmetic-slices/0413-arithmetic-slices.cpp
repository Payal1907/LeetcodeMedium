class Solution {
public:
//this is simple AP series approach that u have to use
    int numberOfArithmeticSlices(vector<int>& nums) {
    int slices = 0;
    if(nums.size()<3) return 0;
    int curr = 0;
    for(int i = 2;i<nums.size();i++)
    {
        if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
        {
            curr++;
            slices+=curr;
        }
        else curr=0;
    } 
    return slices;  
    }
};