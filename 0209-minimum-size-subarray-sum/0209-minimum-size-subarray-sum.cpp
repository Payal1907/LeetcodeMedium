class Solution {
public:
//dekh simple si cheez hai, jbtk sum target ya usse bda hai, tb tk minimum length check krni hai
//aur haa sum mese nums[left] ghtaayegi kyuki aage ka check krna hai, aur left++ kregi, aage se subarray check
//krne ke liye
    int minSubArrayLen(int target, vector<int>& nums) {
    int left  = 0, mini = INT_MAX;
    int sum = 0;
    for(int right = 0;right<nums.size();right++)
    {
        sum+=nums[right];
        while(sum>=target)
        {
            mini=min(mini,right-left+1);
            sum-=nums[left];
            left++;
        }
    } 
    return (mini==INT_MAX)?0:mini;  
    }
};