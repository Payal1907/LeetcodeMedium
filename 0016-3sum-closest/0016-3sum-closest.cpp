class Solution {
public:
//ek to case hai ki sum target ke brabar ho to whi return krde
//dusra case hai ki jo usi time closestSum ko update krne ke liye hai, ki agr diff kam hua to
//closestSum update hoga
//last me bas normal pointers update kiye hai
    int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int closestSum = nums[0]+nums[1]+nums[2];  
    for(int i=0;i<nums.size();i++)
    {
        int j=i+1;
        int k=nums.size()-1;
        while(j<k)
        {
            int currSum = nums[i]+nums[j]+nums[k];
            if(currSum==target) return currSum;
            if(abs(currSum-target)<abs(target-closestSum)) 
            {
                closestSum=currSum;
            }

            if(currSum<target) j++;
            else k--;
        }
    } 
    return closestSum;
    }
};