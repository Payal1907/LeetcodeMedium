class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int length = 0;
        int count =  0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maxi) 
            {
                count++;
                length=max(length,count);
            }
            else count=0;
        }
        return length;
    }
};