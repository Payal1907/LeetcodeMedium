class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int count=0;
        int total = unordered_set<int>(nums.begin(),nums.end()).size();
        for(int i = 0;i<nums.size();i++)
        {
            unordered_set<int> seen;
            for(int j=i;j<nums.size();j++)
            {
                seen.insert(nums[j]);
                if(seen.size()==total) count++;
            }
        }
        return count;   
    }
};