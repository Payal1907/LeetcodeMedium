class Solution {
public:
    int countHillValley(vector<int>& nums) {
    int i=0,j=1;
    int count = 0;
    while(j<nums.size())
    {
        if(nums[i]==nums[j])
        {
            j++;
            continue;
        }
        if(i>0)
        {
            if(nums[i]>nums[i-1] && nums[i]>nums[j] || nums[i]<nums[i-1] && nums[i]<nums[j])
            {
                count++;
            }
            i=j-1;
        }
        i++;
    }   
    return count;
    }
};