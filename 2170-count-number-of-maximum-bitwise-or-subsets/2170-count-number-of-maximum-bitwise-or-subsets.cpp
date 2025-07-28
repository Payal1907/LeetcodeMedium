class Solution {
public:
    int maxOr=0,count=0;
    void func(vector<int>& nums, int index,int currOr)
    {
        if(index==nums.size())
        {
            if(currOr==maxOr)
            {
                count++;
            }
            return;
        }
        func(nums,index+1,currOr|nums[index]);
        func(nums,index+1,currOr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for(auto num : nums)
        {
            maxOr=maxOr|num;
        }
        func(nums,0,0);
        return count;   
    }
};