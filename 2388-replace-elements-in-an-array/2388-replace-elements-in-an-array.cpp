class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
    // unordered_map<int,int> mp;
    // for(auto operation : operations)
    // {
    //     mp[operation[0]]=operation[1];
    // } 
    // for(auto num : nums)
    // {
    //     if(mp.find(num)==mp.end())
    //     mp[num]=num;
    // }
    // for(int i=0;i<nums.size();i++)
    // {
    //     nums[i]=mp[nums[i]];
    // }
    // return nums; ise dekh ke pta chlta hai pisition store krna pdega
    unordered_map<int,int> position;
    for(int i=0;i<nums.size();i++) position[nums[i]]=i;
    for(auto op : operations)
    {
        int old = op[0], neww = op[1];
        int i = position[old];
        nums[i]=neww;
        position.erase(old);
        position[neww]=i;
    }
    return nums;
    }
};