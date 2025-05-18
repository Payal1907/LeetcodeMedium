class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int maxi = nums[0];
    for(int i=0;i<nums.size();i++)
    {
        int curr = nums[i];
        {
            for(int j=i+1;j<nums.size();j++)
            {
                maxi=max(curr,maxi);
                curr=curr*nums[j];
            }
            maxi=max(maxi,curr);
        }
    }
    return maxi;
    }
};