class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    unordered_map<int,int> mp;
    for(auto num : nums)
    {
        mp[num]++;
    } 
    for(auto pair : mp)  
    {
        if(pair.second>std::floor(n/3)) ans.push_back(pair.first);
    }
    return ans;
    }
};