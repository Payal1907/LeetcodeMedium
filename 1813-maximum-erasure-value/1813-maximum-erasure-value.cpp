class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
    int maxi = 0;
    int curr = 0;
    int left  = 0;
    unordered_map<int,int> mp;
    for(int right = 0;right<nums.size();right++)
    {
    //jbtk uska count 1 na ho, tb tk window ko left se shrink krte rehna
        while(mp.count(nums[right]))
        {
            mp.erase(nums[left]);
            curr-=nums[left];
            left++;
        }
        mp[nums[right]]++;
        curr+=nums[right];
        maxi = max(maxi,curr);
    }  
    return maxi; 
    }
};